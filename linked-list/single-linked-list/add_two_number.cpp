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
        printf("%d\n",head->data);
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
int main ()
{
    int x,y;
    scanf("%d%d",&x,&y);

    struct node * head = NULL;
    head = create_number(x,head);

    struct node * head2 = NULL;
    head2 = create_number(y,head2);

    head = reversell(head);
    head2 = reversell(head2);

    printf("First Number\n");
    print(head);

    printf("second Number\n");
    print(head2);

    print(head);
}
