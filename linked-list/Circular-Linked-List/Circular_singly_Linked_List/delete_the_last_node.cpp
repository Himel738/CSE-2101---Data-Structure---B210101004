

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node * create(struct node * head,int data)
{
    head-> link = head;
    head -> data = data;

    return head;
};
struct node * add_end(struct node * tail,struct node * head,int data)
{
    struct node * nodes = (struct node *) malloc(sizeof(struct node));

    nodes -> data = data;
    tail -> link = nodes;
    nodes -> link = head;

    return nodes;
};
struct node * delete_last_node(struct node * head,struct node * tail)
{
    struct node * ptr = head;
    while(ptr-> link != tail)
    {
            ptr = ptr -> link;
    }
    ptr->link = head;
    free(tail);
    return ptr;
};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));
    struct node * tail = create(head,45);

    tail = add_end(tail,head,50);
    tail = add_end(tail,head,60);
    tail = add_end(tail,head,70);

    tail = delete_last_node(head,tail);

    tail=tail -> link;

    do
    {
        printf("%d\n",tail-> data);
        tail = tail -> link;
    }
    while( tail != head);

}
