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
struct node * delet(struct node * head)
{
    struct node *ptr;

    ptr = head -> next;
    head -> prev = NULL;
    head -> next -> prev = NULL;
    head -> next = NULL;

    free(head);
    head = NULL;

    return ptr;

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
     ptr = delet(ptr);

    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr -> next;
    }
}

