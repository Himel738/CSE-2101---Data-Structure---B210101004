#include<stdio.h>
#include<stdlib.h>;

struct node {
   int data;
   struct node * link;
} *top = NULL;

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

void pop()
{
    struct node *temp = top;

    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    top = top -> link;

    free(temp);
    temp = NULL;
}

void peek()
{
    printf("%d\n",top -> data);
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
    //push(15);
    //push(20);
    //push(25);
    //push(30);

    pop();
    peek();

    //print();
}
