

      #include<stdio.h>
#include<stdlib.h>

struct node {
    struct node * prev;
    int data;
    struct node * next;

};

struct node * create_node (struct node * head,int data)
{
    head -> prev = head;
    head -> next = head;
    head -> data = data;

    return head;
};
struct node * add_end(struct node * tail,struct node * head,int data)
{
    struct node * nodes = (struct node *) malloc(sizeof(struct node));
    nodes -> data = data;

    nodes -> prev = tail;
    nodes -> next = head;

    head -> prev = nodes;
    tail -> next = nodes;

    return nodes;
};

struct node * delete_intermediate(struct node * head,int position)
{
   int count = 0;
   struct node * ptr;
   struct node * tail = head;
   do
   {
       ptr = tail -> next;
       count++;
       if(count==position - 1)
       {
           tail -> next = ptr -> next;
           ptr -> next -> prev = tail;

           free(ptr);
       }
       tail = tail -> next;
   } while(tail != head);
};
int main ()
{
    struct node * head = (struct node *) malloc(sizeof(struct node));

    struct node * tail = create_node(head,45);

      tail = add_end(tail,head,50);
      tail = add_end(tail,head,60);
      tail = add_end(tail,head,70);
      tail = add_end(tail,head,80);

      delete_intermediate(head,2);
      //delete_intermediate(head,2);



     if(tail != NULL)
     {


    tail = head;
    do
    {
        printf("%d\n",tail -> data);
        tail = tail -> next;
    }

    while(tail != head);
     }
     else
     {
         printf("List Is Empty\n");
     }
}
