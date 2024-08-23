#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * link;
    int data;
};

void print(struct node * head)
{
    while(head != NULL)
    {
        printf("%d",head->data);
        head = head -> link;
    }
}
struct node * add_node(struct node * head, int value)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> link = NULL;

    new_node -> link = head;
    head = new_node;

    return head;
};
struct node * create_number(int x, struct node * head)
{
    while(x != 0)
    {
        head = add_node(head, x % 10);
        x = x / 10;
    }
    return head;
};
struct node * reversell(struct node * head)
{
    struct node * current = NULL;
    struct node * next = head -> link;

    head -> link = NULL;

    while(next != NULL)
    {
        current = next;
        next = next -> link;
        current -> link = head;
        head = current;
    }
    return head;
}
struct node * add(struct node * head , struct node * head2)
{
    struct node * ptr1 = head;
    struct node * ptr2 = head2;
    struct node * head3 = NULL;

    int sum = 0,carry = 0;

    while(ptr1 != NULL || ptr2 != NULL)
    {
        sum = 0;
        if(ptr1 != NULL)
        {
            sum += ptr1 -> data;
        }
        if(ptr2 != NULL)
        {
            sum += ptr2 -> data;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;

        head3 = add_node(head3,sum);
        if(ptr1)
        {
          ptr1 = ptr1 -> link;
        }
        if(ptr2)
        {
           ptr2 = ptr2 -> link;
        }
    }
    if(carry)
    {
        head3 = add_node(head3,carry);
    }

    return head3;
};
int main ()
{
    int x,y;
    scanf("%d%d",&x,&y);

    struct node * head = NULL;
    struct node * head3 = NULL;
    head = create_number(x,head);

    struct node * head2 = NULL;
    head2 = create_number(y,head2);

    head = reversell(head);
    head2 = reversell(head2);
    head3 = add(head,head2);


    printf("After Adding Number\n");
    print(head3);
}
