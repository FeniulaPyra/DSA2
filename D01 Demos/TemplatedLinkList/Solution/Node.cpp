#include "Node.h"
// see http://msdn.microsoft.com/en-us/library/5zcs50e1.aspx

template <typename T>
Node<T>::Node(T *d) : data(d) {}

template <typename T>
Node<T>::~Node(void) {
	delete data;
}