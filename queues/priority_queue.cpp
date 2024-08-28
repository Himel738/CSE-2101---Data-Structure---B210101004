
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int priority;
    int data;
    struct node * link;
}   *top = NULL;

void enqueue(int priority,int data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node->priority = priority;
    new_node ->data = data;
    new_node -> link = NULL;

    if(top == NULL || top -> priority > priority)
    {
        new_node-> link = top;
        top = new_node;
    }
    else
    {
        struct node * temp = top;

        while(temp != NULL)
        {
            if(temp ->link == NULL && temp -> priority <= priority)
            {
                temp -> link = new_node;
                return;
            }
            else if(temp -> priority <= priority && temp -> link -> priority > priority)
            {
                new_node -> link = temp -> link;
                temp -> link = new_node;
                return;
            }
            temp = temp -> link;
        }
    }
}

void dequeue ()
{
    int data;
    data = top -> data;
    struct node * temp = top;
    top = top -> link;

    free(temp);
    temp = NULL;

    //return data;
}

void print()
{
    struct node * temp = top;

    while(temp != NULL)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

int main ()
{
    enqueue(5,50);
    enqueue(4,60);
    enqueue(3,70);
    enqueue(1,80);
    enqueue(2,90);
    enqueue(5,100);
    enqueue(4,20);

    dequeue();


    print();

}
