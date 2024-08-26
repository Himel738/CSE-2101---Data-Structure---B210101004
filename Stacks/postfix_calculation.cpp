#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct node {
   char data;
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

void push(char data)
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
    int val = temp -> data;
    top = top -> link;

    free(temp);
    temp = NULL;

    return val;
}

void peek()
{
    printf("%d\n",top -> data);
}

void print ()
{
    struct node * temp = top;

    while (temp)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
    }
}

void postfix_calculation(char * s)
{
    for(int i =0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
        {
            push(s[i] - '0');
        }
        else
        {
            if(s[i] == '+')
            {
                int x,y;
                x = pop();
                y = pop();
                push(y + x);
            }
            else if(s[i] == '-')
            {
                int x,y;
                x = pop();
                y = pop();
                push(y - x);
            }
            else if(s[i] == '*')
            {
                int x,y;
                x = pop();
                y = pop();
                push(y * x);
            }
            else if(s[i] == '/')
            {
                int x,y;
                x = pop();
                y = pop();
                push(y / x);
            }
            else if(s[i] == '^')
            {
                int x,y;
                x = pop();
                y = pop();
                push(pow(y,x));
            }
        }
    }

    printf("%d\n",top->data);
}

int main ()
{
    char s[100];
    scanf("%s",s);

    postfix_calculation(s);
}
