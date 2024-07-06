#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * link;
    int data;

};

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    head -> data = 45;
    head -> link = head;

    printf("%d\n",head -> data);
}
