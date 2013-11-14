#pragma once
#include "BSTInterface.h"
#include "Node.h"
class Oak : public BSTInterface
{
public:
	Oak();
	virtual ~Oak();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual Node * getRootNode();

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data) ;

	/* 
	assists in adding recursively
	*/
	bool AddAssist(int data, Node* AddIt);
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data) ;

	/*
	assists in removing recursively  for removing the root or a branch -  with leaves or branches

	Case 1: The Leaf Node
	- *** allready handled in remove and RemoveFinder ***
	- simply delete the node
	Case 2: The Inorder Predecessor
	- replace node to be deleted with its inorder predecessor(the rightmost node in the left subtree of the node to be removed)
	Case 3: The Inorder Predecessor with a Left Child
	- inorder predecessor will never have a right child
	- predecessor’s parent adopts the predecessor’s left child as its right child
	Case 4: The Predecessor is the Left Child
	- the node to be removed is replaced by the predicessor(in this case its left node)
	- along with the predicessor left child if it has one
	Case 5: The Missing Predecessor
	- the node to be removed is replaced by its right child and all its children
	*/
	bool  RemoveFinder(int data, Node* RemoveIt, Node* RemoveItsParent);
	
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear() ;

	/*
	aid to clear/destroy the tree
	*/
	void WildFire(Node* BurnIt) ;
protected:
	Node* Root;
};

