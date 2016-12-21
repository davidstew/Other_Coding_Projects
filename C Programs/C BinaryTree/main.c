#include <stdio.h>
#include "BinaryTree.h"

int main()
{

 int x1 = 5; //works
 int x2 = 6; //no work
 int x3 = 0; //work
 int x4 = 14;//work
 int x5 = 2; //work
 int x61 = 7; //work
 int x71 = 9;
 int x81 = 1;
 int x91 = 11;
 int x101 = 24;
 
 constructor(&Tree1);
 addNode(&x1, &Tree1, intCompare);
 addNode(&x2, &Tree1, intCompare);
 addNode(&x3, &Tree1, intCompare);
 addNode(&x4, &Tree1, intCompare);
 addNode(&x5, &Tree1, intCompare);
 addNode(&x61, &Tree1, intCompare);
 addNode(&x71, &Tree1, intCompare);
 addNode(&x81, &Tree1, intCompare);
 addNode(&x91, &Tree1, intCompare);
 addNode(&x101, &Tree1, intCompare);

 inorder(&Tree1, printInt);

 deleteNode(&x2,&Tree1, intCompare);
 printf("%s \n", "Reprint tree after deletions");
 inorder(&Tree1, printInt);

 printf("%s \n", "Tree #2");

 //double x6 = 17.5;
 double x7 = 675;
 double x8 = 8.5;
 double x9 = 24.5;
 double x10 = 452.5;
 
 constructor(&Tree2);
// addNode(&x6, &Tree2, doubleCompare);
 addNode(&x7, &Tree2, doubleCompare);
 addNode(&x8, &Tree2, doubleCompare);
 addNode(&x9, &Tree2, doubleCompare);
 addNode(&x10, &Tree2, doubleCompare);

 inorder(&Tree2, printDouble);
 deleteNode(&x8,&Tree2, doubleCompare);
 printf("%s \n", "Reprint tree after deletions");
 inorder(&Tree2, printDouble);
}
