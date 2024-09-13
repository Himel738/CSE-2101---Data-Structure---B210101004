

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

int height_of_binary_tree(struct node * root)
{
    if(root == NULL)
        return -1;
    if(root->left == NULL && root->right == NULL)
        return 0;
    int left = height_of_binary_tree(root -> left);
    int right = height_of_binary_tree(root -> right);

    if(left > right)
        return left+ 1;
    else
        return right + 1;
}

int isBalanced(struct node * root)
{
    int l =0, r= 0, lh =0,rh =0, diff =0;

    if(root == NULL)
        return 1;
    l = isBalanced(root -> left);
    r = isBalanced(root -> right);

    if(l&r)
    {
        lh = height_of_binary_tree(root -> left);
        rh = height_of_binary_tree(root -> right);

        diff = abs((lh+1)-(rh+1));

        if(diff <= 1)
            return 1;

    }
    return 0;

}

int main()
{
    struct node *root = create_tree();
    int height = height_of_binary_tree(root);

    if(isBalanced(root))
        printf("Tree Is Height Balanced\n");
    else
        printf("Tree Is Not Height Balanced\n");
}
