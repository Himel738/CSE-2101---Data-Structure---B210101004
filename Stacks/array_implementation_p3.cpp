
#include<stdio.h>
#define MAX 4

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

int main ()
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
            data = topp();
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
