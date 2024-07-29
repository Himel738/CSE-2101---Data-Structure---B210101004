#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * link;
    float co;
    int expo;
};
struct node * insert_node(struct node * head,float co,int expo)
{
    struct node * tail = (struct node *) malloc(sizeof(struct node ));

    tail -> link = NULL;
    tail -> co = co;
    tail -> expo = expo;

    if(head == NULL)
    {
       tail -> link = head;
       head = tail;

       return head;
    }
    else
    {
        struct node * temp = head;

        while(temp != NULL)
        {
        if(temp -> link == NULL && temp -> expo > expo )
        {
            temp -> link = tail;
            return head;
        }

        temp = temp -> link;
        }
    }
};
struct node * create(struct node * head)
{
    int n;
    float co;
    int expo;
    printf("Enter the Number of Terms - ");
    scanf("%d",&n);

    for(int i=0; i < n; i++)
    {
        printf("Enter the Co-Efficient - %d = ", i + 1);
        scanf("%f",&co);

        printf("Enter the Exponent - %d = ", i + 1);
        scanf("%d",&expo);

        head = insert_node(head,co,expo);
    }
    return head;
}
int main ()
{
   struct node * head = NULL;
   struct node * tail = NULL;

   head = create(head);

   tail = head;

   while(tail != NULL)
   {
       printf( "(%.1fx^%d)",tail-> co,tail->expo);
       tail = tail -> link;
       if(tail != NULL)
       {
           printf(" + ");
       }
       else
       {
           printf("\n");
       }
   }
}
