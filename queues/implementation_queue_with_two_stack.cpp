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
    int choice,data;
    struct node * stack1 = NULL;
    struct node * stack2 = NULL;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Quit\n");

        printf("Enter Your Choice: \n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:

            printf("Enter your Data:");
            scanf("%d",&data);
            enqueue(&stack1,data);
            break;
        case 2:
            dequeue(&stack1,&stack2);
            break;
        case 3:
            exit(1);
            break;
        }
    }
}
