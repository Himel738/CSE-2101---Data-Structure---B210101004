
#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    struct node * next;
    int data;
};

struct node * create_node(struct node * head , int data)
{
    struct node *ptr = (struct node *) malloc(sizeof(struct node));

    ptr -> prev = NULL;
    ptr -> next = NULL;
    ptr -> data = data;

    head = ptr;

    return head;
};
struct node * add_node(struct node * head,int data)
{
    struct node * ptr = (struct node *) malloc(sizeof(struct node));

    ptr -> prev = head;
    ptr -> data = data;
    ptr -> next = NULL;

    head ->next = ptr;

    head = ptr;

    return head;
};
void delete_inter(struct node * head,int position)
{

    int count = 0;

    while(head != NULL)
    {
        count++;
        if(count == position)
        {
            head -> prev -> next = head -> next;
            head -> next -> prev = head -> prev;

            free(head);
            head = NULL;

            break;
        }

        head = head -> next;
    }

};

int main ()
{
    struct node * head = NULL;
    struct node * ptr;

    head = create_node(head,45);
    ptr = head;
    head = add_node(head,60);
    head = add_node(head,70);
    head = add_node(head,80);
    head = add_node(head,90);
    head = add_node(head,10);

    delete_inter(ptr,4);


    while(ptr != NULL)
    {
        printf("%d\n",ptr-> data);
        ptr = ptr -> next;
    }
}
