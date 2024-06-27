

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * reversee(struct node *head)
{
    struct node *ptr = NULL;
    struct node * ptr2=NULL;

    while(head != NULL)
    {
        ptr2 = head -> link;
        head -> link = ptr;

        ptr = head;
        head = ptr2;

    }

    head = ptr;

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

    current = reversee(head);

    while(current != NULL)
    {
        printf("%d\n",current -> data);
        current = current -> link;
    }
}

