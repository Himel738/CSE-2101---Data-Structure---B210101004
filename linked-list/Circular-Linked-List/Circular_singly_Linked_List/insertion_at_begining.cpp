#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    head -> link = head;
    head -> data = 45;

    struct node * current = (struct node *) malloc(sizeof(struct node));
    current -> link = head;
    head -> link = current;
    current -> data = 60;

    for(int i =0; i < 2; i++)
    {
        printf("%d\n",current->data);
        current = current -> link;
    }

}
