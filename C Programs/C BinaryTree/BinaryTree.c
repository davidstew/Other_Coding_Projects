#include "BinaryTree.h"
#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>

void constructor(struct BinaryTree* Tree)
{
  Tree->root = NULL;
}

void addNode(void* input, struct BinaryTree* Tree, int (*f)(void*, void*))
{
  struct Nodes* newnode = malloc(sizeof(struct Nodes));
  newnode->value = input;
  newnode->left = NULL;
  newnode->right = NULL;
  
//function pointer, used to be generic and call releveant function to create node depending on 	type
  insertNode(&Tree->root, newnode, f);
  //passing the address of a pointer means a pointer to a pointer can only hold it
}

void insertNode(struct Nodes** root, struct Nodes* newnode, int (*f)(void*, void*))
{ 
  if (*root == NULL)
  {
     *root = newnode;
  }

  else
  {
     if (f(newnode->value, (*root)->value) < 0)
     {
 	insertNode(&(*root)->left, newnode, f);
     }
     else
     {
     	insertNode(&(*root)->right, newnode, f);
	
     }
  }
}

void inorder(struct BinaryTree* Tree, void (*f)(void*))
{
   inordertraversal(Tree->root, f);
}

void inordertraversal(struct Nodes* root, void (*f)(void*))
{
  if (root != NULL)
  {
  	inordertraversal(root->left, f);
	f(root->value);
  	inordertraversal(root->right, f);
  }
}

void deleteNode(void* input, struct BinaryTree* Tree, int (*f)(void*, void*))
{
  deleteTheNode(input, &Tree->root, f);
}

void deleteTheNode(void* input, struct Nodes** root, int (*f)(void*, void*))
{

    struct Nodes** temp;
    struct Nodes** current = root;
    struct Nodes** parent = NULL;

    if(!findNode(input, root, f))
    {
    printf("The value is not in the tree \n");	
    return;
    }

    else
    {
      while (*current != NULL)
      {
	if (f((*current)->value, input) < 0)
	{
	   parent = current;
	   current = &(*current)->right;
        }
	else if (f((*current)->value, input) > 0)
	{
	   parent = current;
	   current = &(*current)->left;
        }
	else 
 	{
	break;
	}
      }
   }

   if ((*current)->left == NULL)
   {
	if (*parent == NULL)
	root = &(*current)->right;
	
	else
	{
	 if (f((*parent)->value, input) < 0) 
	 (*parent)->right = (*current)->right;
	 
         else
	 (*parent)->left = (*current)->right;
	
	//free(*temp); causes unknown error in deleting value x2
	}
    }

  else
  {
	printf("%s", "leel \n");
 	struct Nodes**  parentOfRightMost = current;
    	struct Nodes** rightMost = &(*current)->left;

    	//(Basically finding largest element in left subtree to replace current elements value
   	 while ((*rightMost)->right != NULL)
   	{
		parentOfRightMost = rightMost;
		rightMost = &(*rightMost)->right;
    	}

	//printf("Parent of RightMostNode %i", *(int*)(*parentOfRightMost)->value);
	//printf("Rightmost Node %i", *(int*)(*rightMost)->value);

   	//replace the element in current by the element in rightmost
   	(*current)->value = (*rightMost)->value;
	//printf("current value %i", *(int*)(*rightMost)->value);

	//if rightmost node has left subtree
   	if ((*parentOfRightMost)->right == *rightMost)
   	{
		(*parentOfRightMost)->right = (*rightMost)->left;
		free(*rightMost);
   	}

	//special case
   	else
   	{
   		(*parentOfRightMost)->left = (*rightMost)->left;
   		free(*rightMost);
   	}
 }
	

}

bool findNode(void* input, struct Nodes** root, int (*f)(void*, void*))
{
  if (*root != NULL)
  { 
     if (f((*root)->value, input) == 0)
     {
    	return true;
     }

     else if (f((*root)->value, input) < 0)
     {
     findNode(input, &(*root)->right, f);
     }
     else
     {
     findNode(input, &(*root)->left, f);
     }
  }

  else
  
  return false;
}

void printInt(void *n)
{
  printf("%i \n", *(int*) n);
}

void printDouble(void *n)
{
 printf("%.2lf \n", *(double*) n);
}		

int intCompare(void* int1, void* int2)
{

  return  (*(int*)int1) - (*(int*)int2);
}

int doubleCompare(void* double1, void* double2)
{

  return (*(double*)double1 - *(double*)double2) * 100;
}
