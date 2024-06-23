

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

void traverse (struct node * head)
{
    int count=0;

    if(head == NULL)
    {
        printf("EMpty\n");
    }
    struct node * ptr = head;

    while(ptr != NULL)
    {
        ptr = ptr ->link;
        count++;
    }
    printf("%d\n",count);
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

    //printf("%d\n",current->data);

    traverse(head);



}
