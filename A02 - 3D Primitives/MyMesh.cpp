#include "MyMesh.h"
void MyMesh::Init(void)
{
	m_bBinded = false;
	m_uVertexCount = 0;

	m_VAO = 0;
	m_VBO = 0;

	m_pShaderMngr = ShaderManager::GetInstance();
}
void MyMesh::Release(void)
{
	m_pShaderMngr = nullptr;

	if (m_VBO > 0)
		glDeleteBuffers(1, &m_VBO);

	if (m_VAO > 0)
		glDeleteVertexArrays(1, &m_VAO);

	m_lVertex.clear();
	m_lVertexPos.clear();
	m_lVertexCol.clear();
}
MyMesh::MyMesh()
{
	Init();
}
MyMesh::~MyMesh() { Release(); }
MyMesh::MyMesh(MyMesh& other)
{
	m_bBinded = other.m_bBinded;

	m_pShaderMngr = other.m_pShaderMngr;

	m_uVertexCount = other.m_uVertexCount;

	m_VAO = other.m_VAO;
	m_VBO = other.m_VBO;
}
MyMesh& MyMesh::operator=(MyMesh& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
void MyMesh::Swap(MyMesh& other)
{
	std::swap(m_bBinded, other.m_bBinded);
	std::swap(m_uVertexCount, other.m_uVertexCount);

	std::swap(m_VAO, other.m_VAO);
	std::swap(m_VBO, other.m_VBO);

	std::swap(m_lVertex, other.m_lVertex);
	std::swap(m_lVertexPos, other.m_lVertexPos);
	std::swap(m_lVertexCol, other.m_lVertexCol);

	std::swap(m_pShaderMngr, other.m_pShaderMngr);
}
void MyMesh::CompleteMesh(vector3 a_v3Color)
{
	uint uColorCount = m_lVertexCol.size();
	for (uint i = uColorCount; i < m_uVertexCount; ++i)
	{
		m_lVertexCol.push_back(a_v3Color);
	}
}
void MyMesh::AddVertexPosition(vector3 a_v3Input)
{
	m_lVertexPos.push_back(a_v3Input);
	m_uVertexCount = m_lVertexPos.size();
}
void MyMesh::AddVertexColor(vector3 a_v3Input)
{
	m_lVertexCol.push_back(a_v3Input);
}
void MyMesh::CompileOpenGL3X(void)
{
	if (m_bBinded)
		return;

	if (m_uVertexCount == 0)
		return;

	CompleteMesh();

	for (uint i = 0; i < m_uVertexCount; i++)
	{
		//Position
		m_lVertex.push_back(m_lVertexPos[i]);
		//Color
		m_lVertex.push_back(m_lVertexCol[i]);
	}
	glGenVertexArrays(1, &m_VAO);//Generate vertex array object
	glGenBuffers(1, &m_VBO);//Generate Vertex Buffered Object

	glBindVertexArray(m_VAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);//Bind the VBO
	glBufferData(GL_ARRAY_BUFFER, m_uVertexCount * 2 * sizeof(vector3), &m_lVertex[0], GL_STATIC_DRAW);//Generate space for the VBO

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)0);

	// Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)(1 * sizeof(vector3)));

	m_bBinded = true;

	glBindVertexArray(0); // Unbind VAO
}
void MyMesh::Render(matrix4 a_mProjection, matrix4 a_mView, matrix4 a_mModel)
{
	// Use the buffer and shader
	GLuint nShader = m_pShaderMngr->GetShaderID("Basic");
	glUseProgram(nShader); 

	//Bind the VAO of this object
	glBindVertexArray(m_VAO);

	// Get the GPU variables by their name and hook them to CPU variables
	GLuint MVP = glGetUniformLocation(nShader, "MVP");
	GLuint wire = glGetUniformLocation(nShader, "wire");

	//Final Projection of the Camera
	matrix4 m4MVP = a_mProjection * a_mView * a_mModel;
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4MVP));
	
	//Solid
	glUniform3f(wire, -1.0f, -1.0f, -1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);  

	//Wire
	glUniform3f(wire, 1.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);
	glDisable(GL_POLYGON_OFFSET_LINE);

	glBindVertexArray(0);// Unbind VAO so it does not get in the way of other objects
}
void MyMesh::AddTri(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft)
{
	//C
	//| \
	//A--B
	//This will make the triangle A->B->C 
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);
}
void MyMesh::AddQuad(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft, vector3 a_vTopRight)
{
	//C--D
	//|  |
	//A--B
	//This will make the triangle A->B->C and then the triangle C->B->D
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);

	AddVertexPosition(a_vTopLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopRight);
}
//copied from my E04 code
void MyMesh::GenerateCircle(float a_fRadius, int a_nSubdivisions, vector3 a_v3Color)
{
	Release();
	Init();

	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	/*
		Calculate a_nSubdivisions number of points around a center point in a radial manner
		then call the AddTri function to generate a_nSubdivision number of faces
	*/

	//C
	//| \
	//A--B
	//point A should always be the same I think?

	vector3 A = vector3(0, 0, 0);

	//get the angle between each triangle
	float angleBetween = 360.0f / a_nSubdivisions;

	for (int i = 0; i < a_nSubdivisions; i++) {

		double cAngle = angleBetween * i * PI / 180;
		double bAngle = angleBetween * (i + 1) * PI / 180;

		//just realized I had the trig functions for x and y swapped up i think?
		vector3 B = vector3(cos(bAngle), sin(bAngle), 0) * a_fRadius;
		vector3 C = vector3(cos(cAngle), sin(cAngle), 0) * a_fRadius;

		MyMesh::AddTri(A, B, C);
	}

	// Adding information about color
	//CompleteMesh(a_v3Color);
	//CompileOpenGL3X();
}
void MyMesh::GenerateCube(float a_fSize, vector3 a_v3Color)
{
	if (a_fSize < 0.01f)
		a_fSize = 0.01f;

	Release();
	Init();

	float fValue = a_fSize * 0.5f;
	//3--2
	//|  |
	//0--1

	vector3 point0(-fValue,-fValue, fValue); //0
	vector3 point1( fValue,-fValue, fValue); //1
	vector3 point2( fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	vector3 point4(-fValue,-fValue,-fValue); //4
	vector3 point5( fValue,-fValue,-fValue); //5
	vector3 point6( fValue, fValue,-fValue); //6
	vector3 point7(-fValue, fValue,-fValue); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateCuboid(vector3 a_v3Dimensions, vector3 a_v3Color)
{
	Release();
	Init();

	vector3 v3Value = a_v3Dimensions * 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-v3Value.x, -v3Value.y, v3Value.z); //0
	vector3 point1(v3Value.x, -v3Value.y, v3Value.z); //1
	vector3 point2(v3Value.x, v3Value.y, v3Value.z); //2
	vector3 point3(-v3Value.x, v3Value.y, v3Value.z); //3

	vector3 point4(-v3Value.x, -v3Value.y, -v3Value.z); //4
	vector3 point5(v3Value.x, -v3Value.y, -v3Value.z); //5
	vector3 point6(v3Value.x, v3Value.y, -v3Value.z); //6
	vector3 point7(-v3Value.x, v3Value.y, -v3Value.z); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateCone(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	//generates base
	GenerateCircle(a_fRadius, a_nSubdivisions, a_v3Color);
	//generates the rest - will be the same as generating the base, but the center (point A) will be much higher up now (or will have a -z)
	vector3 A = vector3(0, 0, a_fHeight);
	float angleBetween = 360.0f / a_nSubdivisions;

	for (int i = 0; i < a_nSubdivisions; i++) {
		double cAngle = angleBetween * (i + 1) * PI / 180;
		double bAngle = angleBetween * i * PI / 180;

		vector3 B = vector3(cos(bAngle), sin(bAngle), 0) * a_fRadius;
		vector3 C = vector3(cos(cAngle), sin(cAngle), 0) * a_fRadius;

		//b and c are switched because otherwise the cone is inside out
		MyMesh::AddTri(A, B, C);
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateCylinder(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code	

	vector3 cakeTopper = vector3(0, a_fHeight / 2, 0);
	vector3 cakeBaseCenter = vector3(0, -a_fHeight / 2, 0);

	//how big of a cake piece do you want?
	float angleBetween = 360.0f / a_nSubdivisions;
	
	//makes cake slices :D
	for (int i = 0; i < a_nSubdivisions; i++) {

		float aAngle = angleBetween * i * PI / 180;;
		float bAngle = angleBetween * (i + 1) * PI / 180;;

		//cake slice bottom
		vector3 aTop = vector3(cos(aAngle) * a_fRadius, a_fHeight/2, sin(aAngle) * a_fRadius);
		vector3 bTop = vector3(cos(bAngle) * a_fRadius, a_fHeight / 2, sin(bAngle) * a_fRadius);
		AddTri(cakeTopper, bTop, aTop);

		//cake slice icing! :D
		vector3 aBottom = vector3(cos(aAngle) * a_fRadius, -a_fHeight / 2, sin(aAngle) * a_fRadius);
		vector3 bBottom = vector3(cos(bAngle) * a_fRadius, -a_fHeight / 2, sin(bAngle) * a_fRadius);
		AddTri(cakeBaseCenter, aBottom, bBottom);

		//cake slice wall
		
		AddQuad(aTop, bTop, aBottom, bBottom);
	}
	
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateTube(float a_fOuterRadius, float a_fInnerRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	//float topCenter =  a_fHeight/2; 
	//float bottomCenter = -a_fHeight/2;
	float angleBetween = 360.0f / a_nSubdivisions;

	for (int i = 0; i < a_nSubdivisions; i++) {
		//the start angles of each either edge of the slice
		float aAngle = angleBetween * i * PI / 180;
		float bAngle = angleBetween * (i + 1) * PI / 180;

		//get top 
		vector3 aTopOut = vector3(cos(aAngle) * a_fOuterRadius, a_fHeight / 2, sin(aAngle) * a_fOuterRadius);
		vector3 bTopOut = vector3(cos(bAngle) * a_fOuterRadius, a_fHeight / 2, sin(bAngle) * a_fOuterRadius);
		vector3 aTopIn = vector3(cos(aAngle) * a_fInnerRadius, a_fHeight / 2, sin(aAngle) * a_fInnerRadius);
		vector3 bTopIn = vector3(cos(bAngle) * a_fInnerRadius, a_fHeight / 2, sin(bAngle) * a_fInnerRadius);
		AddQuad(aTopIn, bTopIn, aTopOut, bTopOut);
		
		//get bottom
		vector3 aBottomOut = vector3(cos(aAngle) * a_fOuterRadius, -a_fHeight / 2, sin(aAngle) * a_fOuterRadius);
		vector3 bBottomOut = vector3(cos(bAngle) * a_fOuterRadius, -a_fHeight / 2, sin(bAngle) * a_fOuterRadius);
		vector3 aBottomIn = vector3(cos(aAngle) * a_fInnerRadius, -a_fHeight / 2, sin(aAngle) * a_fInnerRadius);
		vector3 bBottomIn = vector3(cos(bAngle) * a_fInnerRadius, -a_fHeight / 2, sin(bAngle) * a_fInnerRadius);
		AddQuad(aBottomOut, bBottomOut, aBottomIn, bBottomIn);

		//get middles
		AddQuad(aBottomIn, bBottomIn, aTopIn, bTopIn);
		AddQuad(aTopOut, bTopOut, aBottomOut, bBottomOut);

	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateTorus(float a_fOuterRadius, float a_fInnerRadius, int a_nSubdivisionsA, int a_nSubdivisionsB, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	//torus subdivisions
	if (a_nSubdivisionsA < 3)
		a_nSubdivisionsA = 3;
	if (a_nSubdivisionsA > 360)
		a_nSubdivisionsA = 360;

	//circle subidivisions
	if (a_nSubdivisionsB < 3)
		a_nSubdivisionsB = 3;
	if (a_nSubdivisionsB > 360)
		a_nSubdivisionsB = 360;

	Release();
	Init();

	// Replace this with your code
	float thickness = a_fOuterRadius - a_fInnerRadius;
	float angleBetween = 360.0f / a_nSubdivisionsA;
	float circleAngleBetween = 360.0f / a_nSubdivisionsB;

	//https://mathworld.wolfram.com/Torus.html
	//x = (c + a * cos(v)) * cos(u)
	//y = (c + a * cos(v)) * sin(u)
	//z = a * sin(v)
	// where 
	//c = radius of torus hole
	//a = radius of torus tube
	//v = angle around circle?
	//u = angle around torus?
	for (int i = 0; i < a_nSubdivisionsB; i++) {
		//make circle at angle
		float bAngle = angleBetween * i * PI / 180;
		float cAngle = angleBetween * (i + 1) * PI / 180;
		vector3 circleCenter = vector3(cos(bAngle) * a_fInnerRadius, 0, sin(bAngle) * a_fInnerRadius);
		vector3 nextCircleCenter = vector3(cos(cAngle) * a_fInnerRadius, 0, sin(cAngle) * a_fInnerRadius);

		//circlepoint = circlepointatorigin.x + circleCenter.x;
		for (int c = 0; c < a_nSubdivisionsA; c++) {
			float circleAAngle = circleAngleBetween * c * PI / 180;
			float circleBAngle = circleAngleBetween * (c + 1) * PI / 180;

			vector3 A = vector3(
				(a_fInnerRadius + cos(circleAAngle) * thickness) * cos(bAngle),
				(a_fInnerRadius + cos(circleAAngle) * thickness) * sin(bAngle),
				thickness * sin(circleAAngle));
			vector3 B = vector3(
				(a_fInnerRadius + cos(circleBAngle) * thickness) * cos(bAngle),
				(a_fInnerRadius + cos(circleBAngle) * thickness) * sin(bAngle),
				thickness * sin(circleBAngle));
			vector3 C = vector3(
				(a_fInnerRadius + cos(circleAAngle) * thickness) * cos(cAngle), 
				(a_fInnerRadius + cos(circleAAngle) * thickness) * sin(cAngle),
				thickness * sin(circleAAngle));
			vector3 D = vector3(
				(a_fInnerRadius + cos(circleBAngle) * thickness) * cos(cAngle),
				(a_fInnerRadius + cos(circleBAngle) * thickness) * sin(cAngle),
				thickness * sin(circleBAngle));

			AddQuad(C, D, A, B);
		}
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateSphere(float a_fRadius, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	//Sets minimum and maximum of subdivisions
	if (a_nSubdivisions < 1)
	{
		GenerateCube(a_fRadius * 2.0f, a_v3Color);
		return;
	}
	if (a_nSubdivisions > 6)
		a_nSubdivisions = 6;
	//a_nSubdivisions = 10;
	Release();
	Init();

	// Replace this with your code
	//gonna stack some circles
	//circle radius = vector at angle from y axis projected onto y = 0;
	//then just do circle

	//angle between LAYERS
	float angleBetween = 2 * PI / a_nSubdivisions;
	//float distBetween = a_fRadius / a_nSubdivisions;

	//which circle/cylinder are we on - first circle has radius = 0
	for (int i = 0; i < a_nSubdivisions; i++) {

		//height of the stack of circles
		float topDist = a_fRadius * cos(angleBetween / 2 * i);
		float botDist = a_fRadius * cos(angleBetween / 2 * (i + 1));

		//radius of the current circles
		float topRadius = a_fRadius * abs(sin(angleBetween/2 * i));
		float botRadius = a_fRadius * abs(sin(angleBetween/2 * (i+1)));

		//centers of the current circles
		vector3 topCenter = vector3(0,0, topDist);
		vector3 botCenter = vector3(0,0, botDist);
		
		for (int c = 0; c < a_nSubdivisions; c++) {
			//first half of orange slice
			float aAngle = angleBetween * c;
			//second half of orange slice
			float bAngle = angleBetween * (c + 1);
			
			// top circle points
			vector3 topA = vector3(cos(aAngle), sin(aAngle), 0) * topRadius + topCenter;
			vector3 topB = vector3(cos(bAngle), sin(bAngle), 0) * topRadius + topCenter;

			//bottom circle points
			vector3 botA = vector3(cos(aAngle), sin(aAngle), 0) * botRadius + botCenter;
			vector3 botB = vector3(cos(bAngle), sin(bAngle), 0) * botRadius + botCenter;

			AddQuad(botA, botB, topA, topB);
		}
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}