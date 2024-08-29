#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * link;
};

void enqueue(struct node ** front,struct node ** rear,int data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->link = NULL;
    new_node -> data = data;

    if(*front == NULL)
    {
         *front = new_node;
         *rear = new_node;
    }
    else
    {
        (*rear) -> link = new_node;
        *rear = new_node;
    }
}

int dequeue(struct node ** front)
{
    struct node * temp = *front;
    int data = (*front) -> data;
   *front = (*front) -> link;

    free(temp);
    temp = NULL;

    return data;
}

void push(struct node ** stack1,int data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->link = NULL;
    new_node -> data = data;

    new_node -> link = *stack1;
    *stack1 = new_node;
}

int pop(struct node ** stack1)
{
    struct node * temp = *stack1;
    int data = (*stack1) -> data;
    *stack1 = (*stack1) -> link;

    free(temp);
    temp = NULL;

    return data;
}

void reverse_queue(struct node ** front,struct node ** rear,struct node ** stack1)
{

    while(*front)
    {
        push(&(*stack1),dequeue(&(*front)));
    }

    while(*stack1)
    {
        enqueue(&(*front),&(*rear),pop(&(*stack1)));
    }
}

void print(struct node ** front)
{
    struct node * temp = *front;

    while(temp)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

int main ()
{
    struct node * front = NULL;
    struct node * rear = NULL;

    struct node * stack1 = NULL;

    enqueue(&front,&rear,5);
    enqueue(&front,&rear,15);
    enqueue(&front,&rear,50);
    enqueue(&front,&rear,55);
    enqueue(&front,&rear,589);

    reverse_queue(&front,&rear,&stack1);

    print(&front);
}
