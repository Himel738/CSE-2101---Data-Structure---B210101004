


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

struct node * case2 (struct node * root,struct node * ptr,struct node * par)
{
    struct node * child;

    if(ptr ->left != NULL)
        child = ptr -> left;
    else if(ptr -> right != NULL)
        child = ptr -> right;
    if(par == NULL)
        root = child;
    else if(ptr == par -> left)
        par -> left = child;
    else
        par -> right = child;

    free(ptr);

    return root;
};


struct node * deletion(struct node * root,int key)
{
    struct node *ptr,*par;
    ptr = root;
    par == NULL;

    while(ptr != NULL)
    {
        if(key == ptr -> data)
            break;
        par = ptr;

        if(key < ptr -> data)
            ptr = ptr -> left;
        else
            ptr = ptr -> right;
    }

    if(ptr -> left != NULL || ptr -> right != NULL)
        root = case2(root,ptr,par);
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
    root = deletion(root,45);
    print_BST(root);
}

