


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

struct node * leftrotate(struct node * a)
{
    struct node * b = a -> right;
    a -> right = b -> left;
    b -> left = a;

    return b;

};

struct node * rightrotate(struct node * b)
{
    struct node * a = b -> left;
    b -> left = a -> right;
    a -> right = b;

    return a;

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
     root -> left -> left = leftrotate(root -> left-> left);
     root -> left = rightrotate(root -> left);

     printf("%d ",root ->left -> data);
     printf("%d ",root -> left -> left -> data);

}

