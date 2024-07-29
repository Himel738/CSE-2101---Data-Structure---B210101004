
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * link;
    float co;
    int expo;
};
void print(struct node * head)
{
    struct node * tail = NULL;
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
void polynomial_add(struct node *head , struct node * head2)
{
    struct node * ptr1 = head;
    struct node * ptr2 = head2;
    struct node * head3 = NULL;

    while(ptr1 != NULL || ptr2 != NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            head3 = insert_node(head3,ptr1->co + ptr2 -> co,ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2 -> expo)
        {
            head3 = insert_node(head3,ptr1->co,ptr1->expo);
            ptr1 =  ptr1 -> link;
        }

        else if(ptr2->expo > ptr1 -> expo)
        {
            head3 = insert_node(head3,ptr2->co,ptr2->expo);
            ptr2 =  ptr2 -> link;
        }
    }
        while(ptr1 != NULL)
        {
           head3 = insert_node(head3,ptr1->co,ptr1->expo);
            ptr1 =  ptr1 -> link;
        }
        while(ptr2 != NULL)
        {
           head3 = insert_node(head3,ptr2->co,ptr2->expo);
           ptr2 =  ptr2 -> link;
        }
    printf("Added Polynomial \n");
        print(head3);
}

int main ()
{
   struct node * head = NULL;
   struct node * head2 = NULL;

   printf("Enter the First polynomia\n");
   head = create(head);
   printf("Enter the Second polynomia\n");
   head2 = create(head2);
   polynomial_add(head,head2);

}
