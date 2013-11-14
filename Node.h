#pragma once
#include "NodeInterface.h"
class Node : public NodeInterface
{
public:
	Node();
	Node(int data);
	Node(int data, Node * leftchild, Node * rightchild);
	virtual ~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	virtual int getData() ;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual Node * getLeftChild() ;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual Node * getRightChild() ;

	/*
	Sets LeftChild to the given memory location
	*/
	virtual void setLeftChild(Node* newLeftChild);

	/*
	Sets RightChild to the given memory location
	*/
	virtual void setRightChild(Node* newRightChild);

protected:
	Node* LeftChild;
	Node* RightChild;
	int Data;
};

