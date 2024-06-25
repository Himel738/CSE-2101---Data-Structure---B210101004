#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link ;
};


struct node * at_end(struct node * ptr , int data)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr->link = temp;
    return temp;
}

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;

    struct node * ptr = head;
    ptr = at_end(ptr,98);
    ptr = at_end(ptr,3);
    ptr = at_end(ptr,67);

    ptr = head;

    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> link;
    }

}
