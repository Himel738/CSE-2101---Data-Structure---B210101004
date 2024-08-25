#include<stdio.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;

int isFull()
{
    if(top == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop ()
{
    int value;
    if(isEmpty())
    {
        printf("UnderFlow\n");
        return 0;
    }
    value = stack_arr[top];
    top--;

    return value;
}

int topp()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack_arr[top];
}

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = data;
}

void print()
{
    if(top== -1)
    {
        printf("UnderFlow\n");
        return;
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%d\n",stack_arr[i]);
    }
}

void prime_fact(int num)
{
    int i = 2;

    while(num != 1)
    {
        while(num % i == 0)
        {
            push(i);
            num = num / i;
        }
        i++;
    }

    printf("The prime Factorization of a Number\n");
    print();
}

int main ()
{
    int num;
    printf("Enter a Positive Number - \n");
    scanf("%d",&num);
    prime_fact(num);

}
