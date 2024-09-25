
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
    int height;

};

struct node * getSuccessor(struct node * temp)
{
    while(temp -> left != NULL)
        temp = temp -> left;
    return temp;
};

int max(int x,int y)
{
    return (x > y) ? x : y;
}

int height (struct node * n)
{
    if(n == NULL)
        return -1;
    return n->height;
}

int getbalanceF(struct node * n)
{
    if(n == NULL)
        return 0;
    else
        return ((height(n->left)+ 1) - (height(n -> right) + 1));
}

struct node * create_node(int key)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp -> left = NULL;
    temp -> data = key;
    temp -> right = NULL;
    temp -> height = 0;

    return temp;
};

struct node * leftrotate(struct node * a)
{
    struct node * b = a -> right;
    a -> right = b -> left;
    b -> left = a;

    a->height = 1 + max(height(a->left),height(a->right));
    b->height = 1 + max(height(b->left),height(b->right));

    return b;
};

struct node * rightrotate(struct node * b)
{
    struct node * a = b -> left;
    b -> left = a -> right;
    a -> right = b;

    b->height = 1 + max(height(b->left),height(b->right));
    a->height = 1 + max(height(a->left),height(a->right));

    return a;
};

struct node * balance(struct node * n,int bf , int key)
{
    if(bf>1)
    {
        if(key > n -> left->data)
            n -> left = leftrotate(n -> left);
        return rightrotate(n);
    }
    if(bf < -1)
    {
        if(key < n -> right -> data)
            n -> right = rightrotate(n -> right);
        return leftrotate(n);
    }
};

struct node *delete_node(struct node * root,int key)
{
    if(root == NULL)
        return root;
    if(key < root -> data)
        root -> left = delete_node(root -> left , key);
    else if(key > root -> data)
        root -> right = delete_node(root -> right , key);
    else
    {
        if(root -> left == NULL || root -> right == NULL)
        {
            struct node * temp = NULL;

            if(root -> left != NULL)
                temp = root -> left;
            else if(root -> right != NULL)
                temp = root -> right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node * temp = getSuccessor(root -> right);

            root -> data = temp -> data;
            root -> right = delete_node(root -> right, temp -> data);
        }
    }

    if(root == NULL)
        return root;

    //root -> height = 1 + max(height(root -> left),height(root -> right));
    //printf("%d\n",root -> height);
    int bf = getbalanceF(root);

    if(bf>1)
    {
        if(getbalanceF(root -> left) < 0)
            root -> left = leftrotate(root -> left);
        return rightrotate(root);
    }
    if(bf < -1)
    {
        if(getbalanceF(root -> right) > 0)
            root -> right = rightrotate(root -> right);
        return leftrotate(root);
    }

    return root;

};

struct node *insert(struct node * root,int key)
{
    if(root == NULL)
        return (create_node(key));
    if(key < root -> data)
        root -> left = insert(root -> left,key);
    else if(key > root -> data)
        root -> right = insert(root -> right,key);
    else
        return root;

    int left = height(root -> left);
    int right = height (root -> right);

    if(left > right)
        root -> height = 1 + left;
    else
        root -> height = 1 + right;

    int balanceF = getbalanceF(root);

    return balance(root,balanceF,key);
};

void print_preorder(struct node * root)
{
    if(root == NULL)
        return;

    printf("%d ",root -> data);
    print_preorder(root->left);
    print_preorder(root->right);
}

int main ()
{
    struct node * root = NULL;

    root = insert(root,25);
    root = insert(root,10);
    root = insert(root,80);
    root = insert(root,63);
    root = insert(root,65);

    root = delete_node(root,10);

    print_preorder(root);
    printf("\n");

    printf("%d\n",root -> left -> right -> height);


}
