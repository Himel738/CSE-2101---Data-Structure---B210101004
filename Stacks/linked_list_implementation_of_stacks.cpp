#include<stdio.h>
#include<stdlib.h>;

struct node {
   int data;
   struct node * link;
} *top = NULL;

void push(int data)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;

    newnode -> link = top;
    top = newnode;
}

void print ()
{
    struct node * temp = top;

    while (temp)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

int main ()
{
    push(15);
    push(20);
    push(25);
    push(30);

    print();
}
