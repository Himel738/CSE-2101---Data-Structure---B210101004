

#include<stdio.h>
#include<stdlib.h>;

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
    top = top -> link;
    char val = temp -> data;
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

int match_char(char a,char b)
{
    if(a == '[' && b ==']')
        return 1;
    if(a == '{' && b =='}')
        return 1;
    if(a == '(' && b ==')')
        return 1;
    if(a == '<' && b =='>')
        return 1;
    return 0;
}

void isPalindrome(char * s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '<' || s[i] == '[')
            {
                push(s[i]);
            }
        if(s[i] == '}' || s[i] == ')' || s[i] == '>' || s[i] == ']')
        {
            if(isEmpty())
            {
                printf("Invalid Expression\n");
                exit(1);
            }
            else
            {
               if(! match_char(pop(),s[i]))
               {
                   printf("Mismatched\n");
                   exit(1);
               }
            }
        }
    }

    if(isEmpty())
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

int main ()
{
    char s[100];
    scanf("%s",s);

    isPalindrome(s);

}

