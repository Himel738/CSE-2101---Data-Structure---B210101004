#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    int data;
    struct node * next;

};

struct node * create_node (struct node * head,int data)
{
    head -> prev = head;
    head -> next = head;
    head -> data = data;
};
struct node * add_end(struct node * tail,struct node * head,int data)
{
    struct node * nodes = (struct node *) malloc(sizeof(struct node));
    nodes -> data = data;

    nodes -> prev = tail;
    nodes -> next = head;

    head -> prev = nodes;
    tail -> next = nodes;

    return nodes;
};

struct node * delete_last(struct node * head,struct node * tail)
{
    struct node * head2;

    if(head2==head)
    {
        free(head);
        return NULL;
    }
    else
    {
    head2 = tail -> prev;
    head2 -> next = head;
    head -> prev = head2;

    free(tail);

    return head2;
    }
};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    struct node * tail = create_node(head,45);

      tail = add_end(tail,head,50);
      tail = add_end(tail,head,60);
      tail = add_end(tail,head,70);
      tail = add_end(tail,head,80);

      tail = delete_last(head,tail);
      tail = delete_last(head,tail);
      tail = delete_last(head,tail);
     tail = delete_last(head,tail);
      //tail = delete_last(head,tail);
      //tail = delete_last(head,tail);


     if(tail != NULL)
     {


    tail = head;
    do
    {
        printf("%d\n",tail -> data);
        tail = tail -> next;
    }

    while(tail != head);
     }
     else
     {
         printf("List Is Empty\n");
     }
}
