#ifndef BINARYTREE_H
#define BINARYTREE_H


#include <iostream>
#include <stddef.h>
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class BinaryTree
{
	private:
	class Node
	{
	 public:
	 Node* left;
	 Node* right;
	 T value;
	};

	private:
	Node* root;

 public:
 BinaryTree();
 Node* getRoot();
 void addNode(T input);
 void insertNode(Node* &root, Node* & newnode);
 void deleteNode(T input);
 void inorder();
 private:
 void inordertraversal(Node* & root);
 Node* findNode(T input, Node* & root);
};

#endif

