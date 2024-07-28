#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node * create_node(struct node * head,int data)
{
    head -> data = data;
    head -> link = NULL;

    return head;
};

struct node * add_end(struct node *tail,int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp -> link = NULL;
    temp -> data = data;

    tail -> link = temp;

    return temp;
};

struct node * insert_in_sorted_singly_linked_list(struct node * head,struct node * tail,struct node * new_value)
{
    tail = head;

    while(tail != NULL)
    {
        if(tail -> link == NULL && tail -> data < new_value -> data)
        {
            tail -> link = new_value;
            return head;
        }
        else if (tail -> data > new_value -> data)
        {
            new_value -> link = tail;
            head = new_value;
            return head;
        }

        else if(tail -> data < new_value -> data && tail->link -> data >= new_value -> data)
        {
            new_value -> link = tail -> link;
            tail -> link = new_value;
            return head;
        }
        tail = tail -> link;
    }
}

int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));
    struct node * tail;
    tail = create_node(head,45);
    tail = add_end(tail,50);
    tail = add_end(tail,60);
    tail = add_end(tail,70);
    tail = add_end(tail,80);
    tail = add_end(tail,90);

    struct node * new_value = (struct node *) malloc(sizeof(struct node));
    new_value -> data = 10;
    new_value -> link = NULL;
    head = insert_in_sorted_singly_linked_list(head,tail,new_value);

    tail = head;

    while(tail != NULL)
    {
        printf("%d\n",tail-> data);
        tail = tail -> link;
    }
}
