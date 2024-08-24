#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

void push(int data)
{
    first++;

    for(int i = first; i > 0; i--)
    {
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

void print()
{
    for(int i = 0; i <= first; i++)
    {
        printf("%d\n",stack_arr[i]);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    print();
}
