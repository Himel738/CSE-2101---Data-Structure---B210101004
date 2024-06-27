#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * delet(struct node *head,int position)
{
    int count=0;
    if(head->link==NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {

        struct node * ptr=head;
        struct node * ptr2=head;

        while(ptr->link != NULL)
        {
            count++;
            ptr2 = ptr;
            ptr = ptr->link;
            if(count==position-1)
            {
                ptr2->link = ptr->link;
                free(ptr);
                ptr=NULL;
                break;
            }
        }
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

    current = delet(head,2);

    while(current != NULL)
    {
        printf("%d\n",current -> data);
        current = current -> link;
    }
}


