#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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

char pop()
{
    struct node *temp = top;

    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    char val = temp -> data;
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

int precedence(char c)
{
    if(isEmpty())
    {
        return 0;
    }

    char top_op = top->data;

    if ((c == '+') && (top_op == '*' || top_op == '/' || top_op == '^' || top_op == '-' || top_op == '+'))
        return 1;
    else if ((c == '-') && (top_op == '*' || top_op == '/' || top_op == '^' || top_op == '+' || top_op == '-'))
        return 1;
    else if ((c == '*') && (top_op == '^' || top_op == '/' || top_op == '*'))
        return 1;
    else if (( c == '/') && (top_op == '^' || top_op == '*' || top_op == '/'))
        return 1;
    else if (( c == '^') && (top_op == '^'))
        return 1;
    else
        return 0;
}

void infix_to_postfix(char * s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
        {
            printf("%c",s[i]);
        }
        else if(s[i] == '(')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while(top -> data != '(')
            {
                printf("%c",pop());
            }
            pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^')
        {
                while(precedence(s[i]))
                {
                    printf("%c",pop());
                }
                push(s[i]);
        }
    }
    while(!isEmpty())
    {
        printf("%c", pop());
    }
}

int main ()
{
    char s[100];
    scanf("%s",s);

    infix_to_postfix(s);
}
