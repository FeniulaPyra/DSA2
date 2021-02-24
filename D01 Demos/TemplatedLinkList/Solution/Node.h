/*--------------------------------------------------------------------------------------------------
Commented by: [YOUR NAME HERE]
--------------------------------------------------------------------------------------------------*/
#ifndef _NODE_H
#define _NODE_H

template <typename T>
class Node {
public:
	Node(T* d);
	virtual ~Node(void);
	T* data;
	Node* next;
};

#endif //_NODE_H