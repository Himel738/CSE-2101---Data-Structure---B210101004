#include<stdio.h>
#include<stdlib.h>

struct node {

    int data;
    struct node * link;
};
struct node * create(struct node * head , struct node * tail,int data)
{
    head -> link = head;
    head -> data = data;
};
struct node * add_end(struct node * head,struct node * tail,int data)
{
    struct node * nodes = (struct node *) malloc(sizeof(struct node));
    nodes -> data = data;
    nodes -> link = head;

    tail -> link = nodes;

    return nodes;
};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));
    struct node * tail = create(head,tail,45);

    tail = add_end(head,tail,50);
    tail = add_end(head,tail,60);
    tail = add_end(head,tail,70);
    tail = add_end(head,tail,80);

    tail = tail -> link;
    int x;
    bool y = false;
    printf("Enter The Element You Want To Search - ");
    scanf("%d",&x);
    do
    {
       if(tail-> data == x)
       {
           printf("Found");
           y = true;
       }
       tail = tail -> link;
    }
    while(tail != head);

    if(y==false)
    {
        printf("Not Found");
    }

}

