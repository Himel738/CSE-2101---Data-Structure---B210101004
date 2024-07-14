

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

void add_middle(struct node * tail,struct node * head,int data,int position)
{
     struct node * nodes = (struct node *) malloc(sizeof(struct node));
    nodes -> data = data;


    int count = 0;

    do
    {
       count++;
       if(count==position)
       {
         nodes -> prev = tail;
         nodes -> next = tail-> next;
         tail -> next -> prev = nodes;
         tail -> next = nodes;
         break;
       }
        tail = tail -> next;
    }

    while(tail != head);
};

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    struct node * tail = create_node(head,45);

    tail = add_end(tail,head,50);
    tail = add_end(tail,head,60);
    tail = add_end(tail,head,70);
    tail = add_end(tail,head,80);
    tail = head;

    add_middle(tail,head,100,1);
    add_middle(tail,head,200,1);
    add_middle(tail,head,500,4);

    do
    {
        printf("%d\n",tail -> data);
        tail = tail -> next;
    }

    while(tail != head);
}
