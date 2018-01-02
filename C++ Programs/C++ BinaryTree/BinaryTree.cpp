
#include <stddef.h>
#include "BinaryTree.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
BinaryTree<T>::BinaryTree()
{

root = NULL;

}

template <typename T>
void BinaryTree<T>::addNode(T input)
{

 Node* newnode = new Node();
 newnode->value = input;
 newnode->left = NULL;
 newnode->right = NULL;

 insertNode(root, newnode);
}

template <typename T>
void BinaryTree<T>::insertNode(Node*& root, Node* & newnode)
{

 if (root == NULL)
    root = newnode;

 else
 {
  if (newnode->value < root->value)
     insertNode(root->left, newnode);
  else
     insertNode(root->right,newnode);
 }
}

template <typename T>
void BinaryTree<T>::inordertraversal(Node* & root)
{
  if (root != NULL)
  {
  	inordertraversal(root->left);
  	cout << root->value << endl;
  	inordertraversal(root->right);
  }
}

template <typename T>
void BinaryTree<T>::inorder()
{
  inordertraversal(root);
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findNode(T input, Node* & root)
{
  if (root != NULL)
  { 
     if (root->value == input)
     {
    	return root;
     }
     else if (input > root->value)
     {
     findNode(input, root->right);
     }
     else
     {
     findNode(input, root->left);
     }
  }

  else
  return NULL;
}


template <typename T>
void BinaryTree<T>::deleteNode(T input)
{
  	Node* current = root;
  	Node* parent = NULL;

  	Node* foundNode = findNode(input, root);

  	if (foundNode == NULL)
  	{
  	cout << input << " is not in the Tree" << endl;
  	return;
  	}

  	else
  	{
  	 	while (current != NULL)
  		 {
		if (current->value < input)
		{
	  	parent = current;
	  	current = current->right;
		}
		else if (current->value > input)
		{
	  	parent = current;
		current = current->left;
		}
		else if (current->value == input)
		break;
    		}
  	}

  //current node being deleted has no left child. Reconnect parent to current node's right child
  if (current->left == NULL)
  {
    if (parent == NULL)
    parent = current->right;

    else
    {
	if (input > parent->value)
	parent->right = current->right;
	else
	parent->left = current->right;

	delete current;
    }


  }
   	//current node has a left child. Locate the rightmost node in the left subtree of current 		node
   	// and it's parent
  else
  {
    	Node* parentOfRightMost = current;
    	Node* rightMost = current->left;

    	//(Basically finding largest element in left subtree to replace current elements value
   	 while (rightMost->right != NULL)
   	{
		parentOfRightMost = rightMost;
		rightMost = rightMost->right;
    	}

   	//replace the element in current by the element in rightmost
   	current->value = rightMost->value;

	//if rightmost node has left subtree
   	if (parentOfRightMost->right == rightMost)
   	{
		parentOfRightMost->right = rightMost->left;
		delete rightMost;
   	}

	//special case
   	else
   	{
   		parentOfRightMost->left = rightMost->left;
   		delete rightMost;
   	}
  }
}

