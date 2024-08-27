#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * link;
}*front = NULL,*rear = NULL;

int isEmpty()
{
    if(front == NULL)
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
    return front -> data;
}

void enqueue(int data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("NO Space\n");
        exit(1);
    }
    new_node -> data = data;
    new_node-> link = NULL;

    if(rear==NULL)
    {
        front = rear =new_node;
    }
    else
    {
        rear -> link = new_node;
        rear = new_node;
    }
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Underflow\n");
        exit(1);
    }
    struct node * temp = front;
    int data = front -> data;
    front = front -> link;

    free(temp);
    temp = NULL;

    return data;
}

void print()
{
    if(isEmpty())
    {
        printf("There is No Element\n");
        exit(1);
    }
    struct node * temp = front;
    while(temp)
    {
        printf("%d\n",temp -> data);
        temp = temp -> link;
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
