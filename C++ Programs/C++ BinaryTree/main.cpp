
#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main(int argc, char** argv)
{

 BinaryTree<int> Tree;

 Tree.addNode(5);
 Tree.addNode(4);
 Tree.addNode(3);
 Tree.addNode(2);
 Tree.addNode(10);
 Tree.addNode(9);

 Tree.inorder();
 Tree.deleteNode(3);
 Tree.deleteNode(10);
Tree.deleteNode(5);
Tree.deleteNode(35);

 Tree.inorder();


return 0;
}
