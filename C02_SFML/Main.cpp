#include "Main.h"

// Shader sources
/*
Vertex shader R"label()label" is a way of making a large "string" that is able to have break lines for readability.

Vertex shader calculate the position of the vertex in camera space so the output is the reserved word gl_Position will translate
the positionBuffer information, which is a vector 3 needed as a vector 4 so we append a 1.0 at it, the reason its a 1.0 and not 0.0 or other 
number will be clear in future classes, but it basically represents a position.

*/
const GLchar* vertexShader = R"glsl(
	#version 330
	in vec3 positionBuffer;
	void main()
	{
		gl_Position = vec4( positionBuffer, 1.0 );
	}
)glsl";
/*
Fragment shader calculates the color of each pixel displayed
on the window, it will not calculate the positions, those are already computed in 
the vertex shader.

The output is specified by the out variable fragment which is a vector4 (RGBA).

*/
const GLchar* fragmentShader = R"glsl(
	#version 330
	out vec4 fragment;
	void main()
	{
		fragment = vec4( 1.0, 1.0, 1.0, 1.0 );
		return;
	}
)glsl";

int main()
{
	// create the window
	//Set the resolution, Name of the window, style of window, redering context settings
	sf::Window window(sf::VideoMode(800, 600), "SFML_Toolkit", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);//enable vertical sync for the monitor

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit(); //run glew setup

	glEnable(GL_BLEND);	//Enable pixel blend
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //type of the blend function

	glEnable(GL_DEPTH_TEST);// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);	// The Type Of Depth Testing To Do

	glEnable(GL_CULL_FACE);	//Don't show faces from behind

	// load resources, initialize the OpenGL states, get size and position of window ...
	sf::Vector2u size = window.getSize();
	sf::Vector2i pos = window.getPosition();

	//What is the default color of the window when cleared
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

#pragma region Shader Initialization
	// Create and compile the vertex shader
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);//specify the type of shader
	glShaderSource(vertexShaderID, 1, &vertexShader, NULL);//assign space and load from
	glCompileShader(vertexShaderID); //compile the source

	// Create and compile the fragment shader
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);//specify the type of shader
	glShaderSource(fragmentShaderID, 1, &fragmentShader, NULL);//assign space and load from
	glCompileShader(fragmentShaderID);//compile the source

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgramID = glCreateProgram();//Find an "name" (index) for the shader
	glAttachShader(shaderProgramID, vertexShaderID);//attach vertex shader
	glAttachShader(shaderProgramID, fragmentShaderID);//attach fragment shader
	//glBindFragDataLocation(shaderProgramID, 0, "fragment");
	glLinkProgram(shaderProgramID);//Link the shader program
	//Check the program
	GLint result = GL_FALSE;//result is false by default
	GLint log = GL_FALSE;//log is false by default
	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &result);//check if successful
	glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &log);//if not, What went wrong?
	if (log > 0) {//if something went wrong the log will not be empty
		std::vector<char> ProgramErrorMessage(log + 1);//make a vector of chars
		glGetProgramInfoLog(shaderProgramID, log, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);//print the error message to the console
	}
	/*
	We can use multiple shader programs on a single exucutable and as such we should save
	variable we can access from outside this method. As we are only using one and openGL
	machine we can just set it once and be done with it, we just need to make sure we can 
	from memory when we are done
	*/
	glUseProgram(shaderProgramID);//make the compiled program as active
	/*
	the vertex and fragment shaders are compiled already on the shader program so we can get rid
	of them now
	*/
	glDeleteShader(vertexShaderID);//delete the vertex shader
	glDeleteShader(fragmentShaderID);//delete the fragment shader
#pragma endregion
	//---------------------------------------------------------------------------------------------------------
#pragma region Shape Initialization
	// Create Vertex Array Object
	GLuint vao;//"Name" of the vertex array object
	glGenVertexArrays(1, &vao);//find one that is available and store it in this variable
	glBindVertexArray(vao);//make this VAO active

	//Generate the triangle in homogenious coordinats (as we are not using any matrix transitions)
	GLfloat positions[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
	// Create Vertex Buffer Object
	GLuint vbo;//"Name" of the vertex buffered object
	glGenBuffers(1, &vbo);//generate space for this VBO and get the location, store it here
	glBindBuffer(GL_ARRAY_BUFFER, vbo);//make this BVO active
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), &positions, GL_STATIC_DRAW);
	// Get the Attribute of position from the shader program
	GLint positionBufferID = glGetAttribLocation(shaderProgramID, "positionBuffer");
	glEnableVertexAttribArray(positionBufferID);//Make this poditionBufferID active
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);//Say how the information will be used
#pragma endregion

	// run the main loop
	//This is an endless loop that will only finish when the even Close this Window is 
	bool running = true;//control variable
	while (running)//while the control variable is true keep repeating
	{
		// handle events
		sf::Event event;
		//This is a really small example of all the possible events that can occur when the program is executing
		while (window.pollEvent(event))//ask what happened
		{
			if (event.type == sf::Event::Closed)//Is the window closed?
			{
				// end the program
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				running = false;//end the loop
			}
		}

		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Color and draw
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// end the current frame (internally swaps the front and back buffers)
		window.display();
	}

#pragma region Cleanup
	glDeleteProgram(shaderProgramID);//clean the shader program
	glDeleteShader(fragmentShaderID);
	glDeleteShader(vertexShaderID);

	glDeleteBuffers(1, &vbo);//release the memory from the allocation of VBO
	glBindVertexArray(0); // Unbind VAO
	glDeleteVertexArrays(1, &vao);//release the memory from the VAO
#pragma endregion
	return 0;//end the program
}