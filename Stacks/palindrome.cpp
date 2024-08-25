
#include<stdio.h>
#include<stdlib.h>;

struct node {
   int data;
   struct node * link;
} *top = NULL;

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newnode -> data = data;
    newnode -> link = NULL;

    newnode -> link = top;
    top = newnode;

}

int pop()
{
    struct node *temp = top;

    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    top = top -> link;
    int val = temp -> data;
    free(temp);
    temp = NULL;

    return val;


}

void peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    printf("%d\n",top -> data);
}

void print ()
{
    struct node * temp = top;

    while (temp != NULL)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

void isPalindrome(char * s)
{
    int i = 0;
    while(s[i] != 'X')
    {
        push(s[i]);
        i++;
    }
    i++;
    while(s[i])
    {
        if(isEmpty() || s[i] != pop())
        {
            printf("Not Palindrome\n");
            exit(1);
        }
        i++;
    }

    printf("Palindrome\n");
}

int main ()
{
    char s[100];
    scanf("%s",s);

    isPalindrome(s);

}

