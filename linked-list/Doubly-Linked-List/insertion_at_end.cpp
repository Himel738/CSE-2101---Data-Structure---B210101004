#include<stdio.h>
#include<stdlib.h>

struct node {
   struct node * prev;
   int data;
   struct node * next;
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
struct node * add_end(struct node * head , int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    head -> next = ptr;
    ptr -> prev = head;

    head = ptr;

    return head;
};
int main ()
{
    struct node * head = NULL;
    struct node * ptr = NULL;
    head = add(head,45);
    ptr = head;
    head = add_end(head,60);
    head = add_end(head,80);


    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
