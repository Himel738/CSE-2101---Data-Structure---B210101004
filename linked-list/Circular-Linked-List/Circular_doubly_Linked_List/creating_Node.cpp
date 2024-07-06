
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    int data;
    struct node * next;

};

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    head -> data = 45;

    head -> prev = head;
    head -> next = head;

    printf("%d\n",head -> data);
}
