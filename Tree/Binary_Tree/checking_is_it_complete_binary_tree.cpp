
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

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

int isFullBinaryTree(struct node * root , int index , int count)
{
    if(root == NULL)
        return 1;
    if(index >= count)
        return 0;
    else
    {
        int left = isFullBinaryTree(root -> left, 2*index + 1,count);
        int right = isFullBinaryTree(root -> right, 2*index + 2,count);
        return (left && right);
    }
}


int main ()
{
    struct node * root = create_tree();
    int count = count_node(root);
    int index = 0;
    if(isFullBinaryTree(root,index,count))
        printf("Its a Full Binary Tree\n");
    else
        printf("Not a Full Binary Tree\n");
}

