#include "Node.h"


Node::Node()
{
	LeftChild = NULL;
	RightChild = NULL;
}

Node::Node(int data)
{
	Data = data;
	LeftChild = NULL;
	RightChild = NULL;
}

Node::Node(int data, Node * leftchild, Node * rightchild)
{
	Data = data;
	LeftChild = leftchild;
	RightChild = rightchild;
}

Node::~Node()
{
}


/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData()
{
	return Data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node * Node::getLeftChild()
{
	return LeftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node *Node::getRightChild()
{
	return RightChild;
}

/*
Sets LeftChild to the given memory location
*/
void Node::setLeftChild(Node* newLeftChild)
{
	LeftChild = newLeftChild;
}

/*
Sets RightChild to the given memory location
*/
void Node::setRightChild(Node* newRightChild)
{
	RightChild = newRightChild;
}