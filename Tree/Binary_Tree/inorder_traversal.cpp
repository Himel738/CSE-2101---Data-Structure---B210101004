


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

void inorder_traversal(struct node * root)
{
    if(root == NULL)
        return;

    inorder_traversal(root -> left);
    printf("%d ",root->data);
    inorder_traversal(root->right);
}

int main ()
{
    struct node * root = create_tree();
    inorder_traversal(root);

}

