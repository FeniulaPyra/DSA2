/*--------------------------------------------------------------------------------------------------
Commented by: [YOUR NAME HERE]
--------------------------------------------------------------------------------------------------*/
#include "Main.h"

using std::cout;
using std::endl;

int main()
{
	Animal* a = new Animal();
	Animal* d = new Dog();
	Animal* c = new Cat();

	
	Node<Animal>* n1 = new Node<Animal>(a);
	Node<Animal>* n2 = new Node<Animal>(d);
	Node<Animal>* n3 = new Node<Animal>(c);

	n1->next = n2;
	n2->next = n3;
	n3->next = nullptr;

	Node<Animal>* n = n1;
	while (n != nullptr) {
		n->data->print();
		n = n->next;
	}

	delete n1; 
	delete n2;
	delete n3;

	//Ending the program
	std::cout << std::endl;
	std::cout << "Press enter to finish...";
	getchar();
	return 0;
}