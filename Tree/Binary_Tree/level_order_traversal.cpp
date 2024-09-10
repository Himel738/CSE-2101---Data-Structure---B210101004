

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *queue_arr[MAX];
int front = -1;
int rear = -1;


struct node * create_tree()
{
    int choice,data;
    printf("Do You Want to create node ? 0 for No 1 for Yes : ");
    scanf("%d",&choice);

    if(!choice)
    {
        return NULL;
    }
    else
    {
        struct node * new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter Your data; \n");
        scanf("%d",&data);
        new_node->data = data;

        printf("Left Child of %d\n",new_node->data);
        new_node->left = create_tree();

        printf("Right Child of %d\n",new_node->data);
        new_node->right = create_tree();

        return new_node;
    }
};

int count_node(struct node * root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root -> right == NULL)
        return 1;
    else
    {
        int left = count_node(root -> left);
        int right = count_node(root -> right);

        return (1 + left + right);
    }
}

int isFull()
{
    if((front == 0 &&rear == MAX - 1) || (front == rear+1))
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

    if(front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct node * ptr)
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
    if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue_arr[rear] = ptr;
}

struct node * dequeue()
{
     if(isEmpty())
    {
        printf("There is No Element\n");
        exit(1);
    }
    struct node *ptr;
    ptr = queue_arr[front];
    if(front == rear)
    {
        front = rear = -1;
           }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
     front++;
    }
    return ptr;

};

void levelorder_traversal(struct node * root)
{
    struct node * ptr = root;
    if(ptr == NULL)
    {
        printf("The Given Binary Tree is Empty.\n");
        return;
    }
    enqueue(ptr);

    while(!isEmpty())
    {
    ptr = dequeue();

    printf("%d ",ptr -> data);

    if(ptr -> left != NULL)
        enqueue(ptr -> left);
    if(ptr -> right != NULL)
        enqueue(ptr -> right);
    }

}

int main ()
{
    struct node * root = create_tree();
    levelorder_traversal(root);

}

