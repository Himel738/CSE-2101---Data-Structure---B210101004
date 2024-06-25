
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
void insert(struct node ** head)    //pointet to a pointer
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr-> data = 75;
    ptr-> link = NULL;
    ptr->link = *head;
    *head = ptr;

    //return head;

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

    insert(&head);
    current = head;

    while(current != NULL)
    {
        printf("%d\n",current->data);
        current = current->link;
    }

}
