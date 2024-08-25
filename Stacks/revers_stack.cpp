
#include<stdio.h>
#include<stdlib.h>;

struct node {
   int data;
   struct node * link;
};

int isEmpty(struct node * top)
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

struct node * push(struct node * top,int data)
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

    return top;
}

struct node * pop(struct node * top)
{
    struct node *temp = top;

    if(isEmpty(top))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    top = top -> link;

    free(temp);
    temp = NULL;

    return top;
}

void peek(struct node * top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    printf("%d\n",top -> data);
}

void print (struct node *top)
{
    struct node * temp = top;

    while (temp != NULL)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

struct node * another_stack(struct node ** top , struct node * top1)
{
    //struct node * temp = top;

    while(*top)
    {
       top1 =  push(top1,(*top) -> data);
        *top = pop(*top);
    }
    return top1;
}

int main ()
{
    struct node * top  = NULL;
    struct node * top1 = NULL;
    struct node * top2 = NULL;

    top = push(top,15);
    top = push(top,20);
    top = push(top,25);
    top = push(top,40);

    top1 = another_stack(&top,top1);
    top2 = another_stack(&top1,top2);
    top = another_stack(&top2,top);


    print(top);







}
