#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * delet(struct node *head)
{
    if(head->link==NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node * ptr = head;
        struct node * ptr2 = head;

        while(ptr->link != NULL)
        {
            ptr2 = ptr;
            ptr = ptr -> link;
        }

        ptr2 -> link = NULL;
        free(ptr);
        ptr = NULL;
    }

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

