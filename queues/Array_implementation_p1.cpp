#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue_arr[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if(front == -1 || front == rear + 1)
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
    if(rear == MAX - 1)
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
    return queue_arr[front];
}

void enqueue(int data)
{
    if(isFull())
    {
        printf("Queues Overflow\n");
        exit(1);
    }
    if(front == -1)
    {
        front++;
    }
    rear++;
    queue_arr[rear] = data;
}

int dequeue()
{
    if(isEmpty())
    {
        printf("There is No Element\n");
        exit(1);
    }
     int data;
     data = queue_arr[front];
     front++;
     return data;
}

void print()
{
    if(isEmpty())
    {
        printf("There is No Element\n");
        exit(1);
    }

    for(int i = front; i <= rear; i++)
    {
        printf("The Data Found : %d\n",queue_arr[i]);
    }
}

int main ()
{
     int choice,data;
    while(1)
    {
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Print the First Element\n");
    printf("4.Print all the Elements\n");
    printf("5.Quit\n");

    printf("Enter Your Choice: \n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:

        printf("Enter your Data:");
        scanf("%d",&data);
        enqueue(data);
        break;
    case 2:
        data = dequeue();
        printf("%d has been deleted\n",data);
        break;
    case 3:
        data = peek();
        printf("%d is the Top Data\n",data);
        break;
    case 4:
        print();
        break;
    case 5:
        exit(1);
        break;
    }
  }
}
