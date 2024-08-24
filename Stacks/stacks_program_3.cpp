#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack_arr[MAX];
int first = -1;

int isEmpty()
{
    if(first == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(first == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack_arr[0];
}

void push(int data)
{
    first++;

    for(int i = first; i > 0; i--)
    {
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

int pop()
{
    int value;
    value = stack_arr[0];
    for(int i = 0; i < first; i++)
    {
        stack_arr[i] = stack_arr[i+1];
    }
    first--;

    return value;
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
   int choice , data;

    while(1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the Top Element\n");
        printf("4. Print all the Elements\n");
        printf("5. Quit\n");

        printf("Please Enter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the Element to be Pushed: ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted Element is % d\n",data);
            break;
        case 3:
            data = peek();
            printf("The Top Element is %d\n",data);
            break;
        case 4:
            printf("All the Element in Stack is : \n");
            print();
            break;
        case 5:
            return 0;
        }
    }
}
