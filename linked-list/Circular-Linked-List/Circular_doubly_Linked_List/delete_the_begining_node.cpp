

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

struct node * delete_begining(struct node * head,struct node * tail)
{
    struct node * ptr = head -> next;

    tail -> next = ptr;
    ptr-> prev = tail;

    free(head);
    //head-> next = NULL;
    //head -> prev = NULL;

    return ptr;

};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    struct node * tail = create_node(head,45);

      tail = add_end(tail,head,50);
      tail = add_end(tail,head,60);
      tail = add_end(tail,head,70);
      tail = add_end(tail,head,80);

    head  = delete_begining(head,tail);
    head = delete_begining(head,tail);
    head  = delete_begining(head,tail);

    tail = head;
    do
    {
        printf("%d\n",tail -> data);
        tail = tail -> next;
    }

    while(tail != head);
}
