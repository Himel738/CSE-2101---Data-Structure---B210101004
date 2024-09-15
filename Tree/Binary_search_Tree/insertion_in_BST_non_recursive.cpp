
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *create_tree()
{
    int input,data;
    printf("Do You Want to Add a Node? 0 for No 1 for Yes\n");
    scanf("%d",&input);

    if(!input)
    {
        return NULL;
    }
    else
    {
        struct node * new_node = (struct node *) malloc(sizeof(struct node));
        printf("Enter the Data: ");
        scanf("%d",&data);

        new_node->data = data;

        printf("Left Child of %d\n",new_node->data);
        new_node->left = create_tree();

        printf("Right Child of %d\n",new_node->data);
        new_node->right = create_tree();

        return new_node;

    }
};

struct node * create_node(int data)
{
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->data = data;
    new_node->right = NULL;

    return new_node;
};

struct node * insertion_element(struct node * root,int key)
{
    if(root == NULL)
        root = create_node(key);
    else if(key < root -> data)
        root -> left = insertion_element(root -> left , key);
    else if(key > root -> data)
        root -> right = insertion_element(root -> right,key);
    else
        printf("Duplicate Key\n");
    return root;
};

void print_BST(struct node * root)
{
    if(root == NULL)
        return;
    printf("%d ",root ->data);
    print_BST(root -> left);
    print_BST(root -> right);
}

int main()
{
    struct node *root = create_tree();
    root = insertion_element(root,45);

    print_BST(root);

}
