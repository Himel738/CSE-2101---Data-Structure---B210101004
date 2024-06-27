
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * delet(struct node *head)
{
    struct node * ptr;
    ptr = head;

    while(ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    free(ptr->link);
    ptr->link = NULL;

    return head;
}
int main ()
{
    struct node *head = (struct node *) malloc(sizeof(struct node));

    head-> data = 45;
    head ->link = NULL;

    struct node *current = (struct node *) malloc(sizeof(struct node));
    current -> data = 50;
    head -> link = current;
    current -> link = NULL;

    current = (struct node *) malloc (sizeof(struct node));
    current -> data = 60;
    head -> link -> link = current;
    current -> link = NULL;

    current = delet(head);

    while(current != NULL)
    {
        printf("%d\n",current -> data);
        current = current -> link;
    }
}

