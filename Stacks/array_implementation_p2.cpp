
#include<stdio.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;
int pop ()
{
    int value;
    if(top == -1)
    {
        printf("UnderFlow\n");
        return 0;
    }
    value = stack_arr[top];
    top--;

    return value;
}
void push(int data)
{
    if(top==MAX-1)
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

int main ()
{
    push(1);
    push(2);
    push(3);
    push(4);

    int data;
    data = pop();
    print();
    push(4);
    print();
}
