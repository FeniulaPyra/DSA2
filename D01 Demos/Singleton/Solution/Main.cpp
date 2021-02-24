/*--------------------------------------------------------------------------------------------------
Programmer: labigm@rit.edu
--------------------------------------------------------------------------------------------------*/
#include <ostream>

class Foo
{
	static Foo* instance; // will be shared among all objects instantiated of this class
	int var;
private:
	Foo(){ var = 10; };
	Foo(Foo const& other){};
	Foo& operator=(Foo const& other){};
public:
	// Because of the static can be called even without instantiating an object of this class
	static Foo* GetInstance()//Will act as the constructor if the object is not defined 
	{
		if (instance == nullptr)//Is the instance pointer empty?
		{
			instance = new Foo();//create a new pointer
		}
		return instance;//return the pointer whatever the case
	}
	static void ReleaseInstance()//Will act as the destructor if the object is already defined
	{
		if (instance != nullptr)//is the instance already allocated in memory?
		{
			delete instance;//it is! so delete it
			instance = nullptr;//make it point to a safe location
		}
	}
};
Foo* Foo::instance = nullptr;//make the Foo pointer inside of the Foo class point to a safe location
int main(void)
{
	Foo* oFoo = Foo::GetInstance();//Get the instance so I can do something with it (or construct it if not existent)
	if (true)//just a way of placing the scope
	{
		Foo* oFoo1 = Foo::GetInstance();//Get the instance so I can do something with it (or construct it if not existent)
	}
	oFoo->ReleaseInstance();//This is the very last Foo object to access the class... Release the memory
	return 0;
}

