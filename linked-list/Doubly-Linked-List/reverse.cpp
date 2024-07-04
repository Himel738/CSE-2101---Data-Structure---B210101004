#include <stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    struct node * next;
    int data;
};

struct node * add_empty(struct node * head , int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;

    head = ptr;

    return head;
};
struct node * add_end(struct node * head , int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    head -> next = ptr;
    ptr -> prev = head;

    head = ptr;

    return head;
};
struct node * reverse (struct node * head)
{
    struct node * ptr=NULL;
    struct node * ptr2=NULL;
    struct node * ptr3=NULL;

    while(head != NULL)
    {
        //printf("1\n");
        ptr3 = ptr;
        ptr = head -> next;
        ptr2 = head -> prev;
        head -> prev = ptr;
        head -> next = ptr2;



        head = head -> prev;
    }
    head = ptr3;
    return head;
};
int main ()
{
    int data,n;
    printf("enter the number of node - ");
    scanf("%d",&n);
    printf("enter the data of 1st node - ");
    scanf("%d",&data);
    struct node * head = NULL;
    head = add_empty(head,data);
    struct node * ptr = head;

    for(int i = 1; i < n; i++)
    {
        printf("enter the data of %d  node - ",i+1);
        scanf("%d",&data);
        head = add_end(head,data);
    }

    ptr = reverse(ptr);

    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}
