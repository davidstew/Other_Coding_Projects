#ifndef LINKEDLIST.H
#define LINKEDLIST.H

struct LinkedList {

    struct Node
    {
    void* value;
    struct Node* next;
    };

    struct Node* head;
};

void constructor (struct LinkedList*);
void addNode(void*, struct LinkedList*);
int isEmpty();

void printList(const struct LinkedList* List, void f(void*));
//void printList(const struct LinkedList* List, void(*)(void*));
void removeFront(struct LinkedList*);

void removeFront(struct LinkedList* List)
{
    struct Node* temp = List->head;
    List->head = List->head->next;
    free(temp);
}


void printList(const struct LinkedList* List, void f(void*))
//void printList(const struct LinkedList* List, void(*ptr)(void*))
{
    struct Node* nodeptr = List->head;
    {
        while (nodeptr != NULL)
        {
        //(ptr)(nodeptr->value);
        f(nodeptr->value);
        nodeptr = nodeptr->next;
        }
    }

}

int isEmpty(struct LinkedList* List)
{
    if (List->head == NULL)
        return 1;
    else
        return 0;
}

void constructor(struct LinkedList* List)
{
    List->head = NULL;
}

void addNode(void* input, struct LinkedList* List)
{
    if (isEmpty(&List))
    {
        struct Node* newnode = malloc(sizeof(struct Node));
        newnode->value = input;
        newnode->next = NULL;
        List->head = newnode;
    }
    else
    {
        struct Node* newnode = malloc(sizeof(struct Node));
        newnode->value = input;
        newnode->next = List->head;
        List->head = newnode;
    }
}

void printInt(void *n)
{
   printf(" %d", *(int *)n);
}

void printChar(void *c)
{
   printf(" %c", *(char *)c);
}

void printDouble(void *c)
{
    printf("%s","hello");
   printf(" %f", *(double *)c);
}
#endif

