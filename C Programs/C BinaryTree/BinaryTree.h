#include <stdbool.h>

struct BinaryTree
{
  struct Nodes
  {
   struct Nodes* left;
   struct Nodes* right;
   void* value;
  } Node;

  struct Nodes* root;

} Tree1, Tree2;

void constructor(struct BinaryTree* Tree); 
void addNode(void* input, struct BinaryTree* Tree, int (*f)(void*, void*));
void insertNode(struct Nodes** root, struct Nodes* newnode, int (*f)(void*, void*));
bool findNode(void* input, struct Nodes** root, int (*f)(void*, void*));
void inordertraversal(struct Nodes*, void (*f)(void*));
void inorder(struct BinaryTree* Tree, void (*f)(void*));
void deleteNode(void* input, struct BinaryTree* Tree, int (*f)(void*, void*));
void deleteTheNode(void* input, struct Nodes** root, int (*f)(void*, void*));
void printInt(void* n);
void printDouble(void* n);
int intCompare(void*, void*);
int doubleCompare(void*, void*);
