
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node * stack_tree[MAX];
int top = -1;

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

void push(struct node * ptr)
{
    if(top ==(MAX-1))
    {
        printf("Overflow\n");
        exit(1);
    }

    top++;
    stack_tree[top] = ptr;

}

struct node * pop()
{
    struct node *ptr;

    if(top == -1)
    {
        printf("Stack Is Underflow\n");
        exit(1);
    }
    ptr = stack_tree[top];
    top--;

    return ptr;

};

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void inorder_traversal(struct node * root)
{
    struct node * ptr = root;

    while(1)
    {
        while(ptr -> left != NULL)
        {
            push(ptr);
            ptr = ptr -> left;
        }
        while(ptr -> right == NULL)
        {
            printf("%d ",ptr -> data);

            if(isEmpty())
                return;
            ptr = pop();
        }
        printf("%d ",ptr -> data);
        ptr = ptr -> right;
    }
}

int main ()
{
    struct node * root = create_tree();
    inorder_traversal(root);

}

