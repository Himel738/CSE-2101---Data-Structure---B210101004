

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

struct node * non_recursive_search(struct node * root,int key)
{
    while(root != NULL)
    {
        if(key < root -> data)
            root = root -> left;
        else if(key > root -> data)
            root = root -> right;
        else
            return root;
    }
     return NULL;
};

int main()
{
    struct node *root = create_tree();

    if(non_recursive_search(root,45))
        printf("The Element Found\n");
    else
        printf("Not Found\n");
}
