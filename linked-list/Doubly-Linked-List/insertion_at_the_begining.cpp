#include<stdio.h>
#include<stdlib.h>

struct node {
   struct node * prev;
   int data;
   struct node * next;
};
struct node * add(struct node * head , int data)
{
    struct node * ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    head = ptr;

    return head;
};
struct node * add_beg(struct node * head,int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    ptr->prev = NULL;
    ptr->next = head;
    head -> prev = ptr;
    //head -> next = NULL;

    head = ptr;

    return ptr;
};
int main ()
{
    struct node * head = NULL;
    struct node * ptr = NULL;
    head = add(head,45);
    head = add_beg(head,60);
    head = add_beg(head,75);

    ptr = head;

    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }

}
