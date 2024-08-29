#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * link;
};

void push(struct node **stack1,int data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> link = NULL;

    new_node -> link = *stack1;
    *stack1 = new_node;
}

void pop(struct node ** stack1,struct node **stack2)
{
    if(*stack2 == NULL)
    {
        while(*stack1)
        {
            struct node * temp = *stack1;
            push(&(*stack2),(*stack1) -> data);
            *stack1 = (*stack1) -> link;
            free(temp);
            temp = NULL;
        }

        struct node * temp = *stack2;
        int data;
        data = (*stack2) -> data;
        *stack2 = (*stack2) -> link;

        free(temp);
        temp = NULL;

        printf("The data has been deleted - %d\n",data);
    }
    else
    {
        struct node * temp = *stack2;
        int data;
        data = (*stack2) -> data;
        *stack2 = (*stack2) -> link;

        free(temp);
        temp = NULL;

        printf("The data has been deleted - %d\n",data);
    }
}

void enqueue(struct node ** stack1,int data)
{
    push(&(*stack1),data);
}

void dequeue(struct node ** stack1,struct node ** stack2)
{
    pop(&(*stack1),&(*stack2));
}

int main ()
{
    struct node * stack1 = NULL;
    struct node * stack2 = NULL;

    enqueue(&stack1,5);
    enqueue(&stack1,10);
    enqueue(&stack1,15);
    enqueue(&stack1,25);
    enqueue(&stack1,30);
    enqueue(&stack1,155);

    dequeue(&stack1,&stack2);
    dequeue(&stack1,&stack2);
    dequeue(&stack1,&stack2);
    dequeue(&stack1,&stack2);
    dequeue(&stack1,&stack2);
    dequeue(&stack1,&stack2);

}
