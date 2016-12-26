#include <stdio.h>
#include "LinkedList.h"

int main()
{
    struct LinkedList List;

    constructor(&List);
    int int1 = 5;
    int int2 = 4;
    int int3 = 3;
    int int4 = 2;
    int int5 = 1;

    addNode(&int1, &List);
    addNode(&int2, &List);
    addNode(&int3, &List);
    addNode(&int4, &List);
    addNode(&int5, &List);

    printList(&List,printInt);

    removeFront(&List);

    printf("\n");

    printList(&List, printInt);

    printf("\n");

    struct LinkedList List2;


    constructor(&List2);

    char a = 'a';
    char b = 'b';

    addNode(&a, &List2);
    addNode(&b, &List2);

    printList(&List2, printChar);

    return 0;
}
