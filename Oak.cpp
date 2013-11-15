#include "Oak.h"


Oak::Oak()
{
	Root = NULL;
	TestBit = true;  // if true print out test clauses
}


Oak::~Oak()
{
	clear();
	if (TestBit)
	{
		cout << "passed here test section : " << 1 << endl;
	}
}

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
Node * Oak::getRootNode()
{
	return Root;
	if (TestBit)
	{
		cout << "passed here test section : " << 2 << endl;
	}
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool Oak::add(int data)
{
	if (Root != NULL)
	{
		if (data == Root->getData())  // if value exists return false
		{
			if (TestBit)
			{
				cout << "passed here test section : " << 3 << endl;
			}
			return false;
		}
		if (data < Root->getData())
		{
			if (Root->getLeftChild() != NULL)  // if not NULL continue searching for location to add
			{
				return AddAssist(data, Root->getLeftChild());
			}
			else
			{
				Root->setLeftChild(new Node(data));
				if (TestBit)
				{
					cout << "passed here test section : " << 4 << endl;
				}
				AddCount++;
				return true;
			}
		}
		if (data > Root->getData())
		{
			if (Root->getRightChild() != NULL)
			{
				return AddAssist(data, Root->getRightChild());
			}
			else
			{
				Root->setRightChild(new Node(data));
				if (TestBit)
				{
					cout << "passed here test section : " << 5 << endl;
				}
				AddCount++;
				return true;
			}
		}
	}
	else
	{
		Root = new Node(data);
		if (TestBit)
		{
			cout << "passed here test section : " << 6 << endl;
		}
		AddCount++;
		return true;
	}
}

/*
assists in adding recursively
*/
bool  Oak::AddAssist(int data, Node* AddIt)
{
	if (data == AddIt->getData())
	{
		if (TestBit)
		{
			cout << "passed here test section : " << 7 << endl;
		}
		return false;
	}
	if (data < AddIt->getData())
	{
		if (AddIt->getLeftChild() != NULL)
		{
			return AddAssist(data, AddIt->getLeftChild());
		}
		else
		{
			AddIt->setLeftChild(new Node(data));
			if (TestBit)
			{
				cout << "passed here test section : " << 8 << endl;
			}
			AddCount++;
			return true;
		}
	}
	if (data > AddIt->getData())
	{
		if (AddIt->getRightChild() != NULL)
		{
			return AddAssist(data, AddIt->getRightChild());
		}
		else
		{
			AddIt->setRightChild(new Node(data));
			if (TestBit)
			{
				cout << "passed here test section : " << 9 << endl;
			}
			AddCount++;
			return true;
		}
	}

}

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool Oak::remove(int data)
{
	if (Root != NULL)// empty?
	{
		//Case 1: The Leaf Node
		//Case 2: The Inorder Predecessor
		//Case 3: The Inorder Predecessor with a Left Child
		//Case 4: The Predecessor is the Left Child
		//Case 5: The Missing Predecessor
		RemoveFinder(data, Root, Root);
	}
	else // if empty
	{
		if (TestBit)
		{
			cout << "passed here test section : " << 10 << endl;
		}
		return false;
	}
}

/*
assists in removing by finding the node containing the data to be removed recursively
covers 
Case 1: The Leaf Node
- *** allready handled in remove and RemoveFinder ***
- simply delete the node
*/
bool  Oak::RemoveFinder(int data, Node* RemoveIt, Node* RemoveItsParent)
{
	if (RemoveIt->getData() == data)// match is found
	{
		//Case 1: The Leaf Node
		//-simply delete the node
		if (RemoveIt->getLeftChild() == NULL && RemoveIt->getRightChild() == NULL) // it is a leaf : Case 1
		{
			if (RemoveItsParent->getData() == RemoveIt->getData()) // it is the root
			{
				delete RemoveIt;
				DeleteCount++;
				Root = NULL;
				if (TestBit)
				{
					cout << "passed here test section : " << 11 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getLeftChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				delete RemoveIt;
				DeleteCount++;
				RemoveItsParent->setLeftChild(NULL);
				if (TestBit)
				{
					cout << "passed here test section : " << 12 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getRightChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				delete RemoveIt;
				DeleteCount++;
				RemoveItsParent->setRightChild(NULL);
				if (TestBit)
				{
					cout << "passed here test section : " << 13 << endl;
				}
				return true;
			}
		}

		//Case 2: The Inorder Predecessor
		//- replace node to be deleted with its inorder 
		//     predecessor(the rightmost node in the left subtree of the node to be removed)
		//Case 3: The Inorder Predecessor with a Left Child
		//- inorder predecessor will never have a right child
		//- predecessor’s parent adopts the predecessor’s left child as its right child
		if (RemoveIt->getLeftChild() != NULL && RemoveIt->getLeftChild()->getRightChild() != NULL)
		{
			Node* TmpPred;
			Node* TmpParentOfPred;
			TmpPred = RemoveIt->getLeftChild();
			while (TmpPred->getRightChild() != NULL)
			{
				TmpParentOfPred = TmpPred;
				TmpPred = TmpPred->getRightChild();
			}
			if (RemoveItsParent->getData() == RemoveIt->getData()) // it is the root
			{
				if (TmpPred->getLeftChild() == NULL)  // Case 2 if true
				{
					Root = TmpPred;
					TmpParentOfPred->setRightChild(NULL);
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					if (TestBit)
					{
						cout << "passed here test section : " << 14 << endl;
					}
					return true;
				}
				else  // Case 3 otherwise
				{
					Root = TmpPred;
					TmpParentOfPred->setRightChild(TmpPred->getLeftChild());
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					return true;
				}
			}
			if (RemoveItsParent->getLeftChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				if (TmpPred->getLeftChild() == NULL)  // Case 2 if true
				{
					RemoveItsParent->setLeftChild(TmpPred);
					TmpParentOfPred->setRightChild(NULL);
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					if (TestBit)
					{
						cout << "passed here test section : " << 15 << endl;
					}
					return true;
				}
				else  // Case 3 otherwise
				{
					RemoveItsParent->setLeftChild(TmpPred);
					TmpParentOfPred->setRightChild(TmpPred->getLeftChild());
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					if (TestBit)
					{
						cout << "passed here test section : " << 16 << endl;
					}
					return true;
				}
			}
			if (RemoveItsParent->getRightChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				if (TmpPred->getLeftChild() == NULL)  // Case 2 if true
				{
					RemoveItsParent->setRightChild(TmpPred);
					TmpParentOfPred->setRightChild(NULL);
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					if (TestBit)
					{
						cout << "passed here test section : " << 17 << endl;
					}
					return true;
				}
				else  // Case 3 otherwise
				{
					RemoveItsParent->setRightChild(TmpPred);
					TmpParentOfPred->setRightChild(TmpPred->getLeftChild());
					TmpPred->setLeftChild(RemoveIt->getLeftChild());
					TmpPred->setRightChild(RemoveIt->getRightChild());
					delete RemoveIt;
					DeleteCount++;
					if (TestBit)
					{
						cout << "passed here test section : " << 18 << endl;
					}
					return true;
				}
			}
		}

		//Case 4: The Predecessor is the Left Child
		//- the node to be removed is replaced by the predicessor(in this case its left node)
		//- along with the predicessor left child if it has one
		if (RemoveIt->getLeftChild() != NULL && RemoveIt->getLeftChild()->getRightChild() == NULL)
		{
			if (RemoveItsParent->getData() == RemoveIt->getData()) // it is the root
			{
				Root = RemoveIt->getLeftChild();
				Root->setRightChild(RemoveIt->getRightChild());
				delete RemoveIt;
				DeleteCount++;
				if (TestBit)
				{
					cout << "passed here test section : " << 19 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getLeftChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				RemoveItsParent->setLeftChild(RemoveIt->getLeftChild());
				RemoveItsParent->getLeftChild()->setRightChild(RemoveIt->getRightChild());
				delete RemoveIt;
				DeleteCount++;
				if (TestBit)
				{
					cout << "passed here test section : " << 20 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getRightChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				RemoveItsParent->setRightChild(RemoveIt->getLeftChild());
				RemoveItsParent->getRightChild()->setRightChild(RemoveIt->getRightChild());
				delete RemoveIt;
				DeleteCount++;
				if (TestBit)
				{
					cout << "passed here test section : " << 21 << endl;
				}
				return true;
			}
		}

		//Case 5: The Missing Predecessor
		//- the node to be removed is replaced by its right child and all its children
		if (RemoveIt->getLeftChild() == NULL)
		{
			if (RemoveItsParent->getData() == RemoveIt->getData()) // it is the root
			{
				Root = RemoveIt->getRightChild();
				delete RemoveIt;
				DeleteCount++;
				if (TestBit)
				{
					cout << "passed here test section : " << 22 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getLeftChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				RemoveItsParent->setLeftChild(RemoveIt->getRightChild());
				delete RemoveIt;
				DeleteCount++;
				if (TestBit)
				{
					cout << "passed here test section : " << 23 << endl;
				}
				return true;
			}
			if (RemoveItsParent->getRightChild()->getData() == RemoveIt->getData()) // it is the left branch/child
			{
				RemoveItsParent->setRightChild(RemoveIt->getLeftChild());
				delete RemoveIt;
				if (TestBit)
				{
					cout << "passed here test section : " << 24 << endl;
				}
				return true;
			}
		}

	}
	else //not found
	{
		if (RemoveIt->getLeftChild() != NULL)
		{
			if (RemoveIt->getData() > data)  // if desireed data is less than current location go left in tree
			{
				return RemoveFinder(data, RemoveIt->getLeftChild(), RemoveIt);
			}
			else
			{
				if (TestBit)
				{
					cout << "passed here test section : " << 25 << endl;
				}
				return false;
			}
		}
		if (RemoveIt->getRightChild() != NULL)
		{
			if (RemoveIt->getData() > data) // if desireed data is greater than current location go right in tree
			{
				return RemoveFinder(data, RemoveIt->getRightChild(), RemoveIt);
			}
			else
			{
				if (TestBit)
				{
					cout << "passed here test section : " << 26 << endl;
				}
				return false;
			}
		}
	}
}


/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void Oak::clear()
{
	if (Root == NULL){}
	else
	{
		if (Root->getLeftChild() != NULL)
			WildFire(Root->getLeftChild());
		if (Root->getRightChild() != NULL)
			WildFire(Root->getRightChild());
		delete Root;
		DeleteCount++;
		Root == NULL;
	}
}

/*
aid to clear/destroy the tree
*/
void Oak::WildFire(Node* BurnIt)
{
	if (BurnIt->getLeftChild() != NULL)
		WildFire(BurnIt->getLeftChild());
	if (BurnIt->getRightChild() != NULL)
		WildFire(BurnIt->getRightChild());
	if (TestBit)
	{
		cout << "passed here test section : " << 26 << endl;
	}
	delete BurnIt;
	DeleteCount++;
}