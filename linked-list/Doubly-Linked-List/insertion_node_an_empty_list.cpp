
#include<stdio.h>
#include<stdlib.h>

struct node {
   struct node * prev;
   int data;
   struct node *next;
};
struct node * add(struct node * head,int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    head = ptr;
    return head;
};
int main ()
{
    struct node * head=NULL;

    head = add(head,60);
    printf("%d\n",head->data);
}
