
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node * create(struct node * head,int data)
{
    head-> link = head;
    head -> data = data;

    return head;
};
struct node * add_end(struct node * tail,struct node * head,int data)
{
    struct node * nodes = (struct node *) malloc(sizeof(struct node));

    nodes -> data = data;
    tail -> link = nodes;
    nodes -> link = head;

    return nodes;
};
void delete_intermediate_node(struct node * head,struct node * tail,int position)
{
    struct node * ptr = head;
    int count = 0;

    while(ptr != tail)
    {
        count++;

        if(count ==(position-1))
        {
            struct node * next = ptr -> link;
            ptr -> link = next -> link;

            free(next);
            next ->link = NULL;
            break;
        }
        ptr = ptr -> link;
    }

};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));
    struct node * tail = create(head,45);

    tail = add_end(tail,head,50);
    tail = add_end(tail,head,60);
    tail = add_end(tail,head,70);

    delete_intermediate_node(head,tail,2);

    tail=tail -> link;

    do
    {
        printf("%d\n",tail-> data);
        tail = tail -> link;
    }
    while( tail != head);

}
