
#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * createNode(char data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> left = NULL;
    ptr -> data = data;
    ptr -> right = NULL;

    return ptr;
};

int searchIn(char inArr[],char data,int inStart,int inEnd)
{
    int i;
    for(i = inStart; i<= inEnd; i++)
    {
        if(inArr[i] == data)
            return i;
    }
}

struct node *constructBT(char inArr[],char postArr[],int inStart,int inEnd)
{
    static int postIndex = inEnd;
    if(inStart > inEnd)
        return NULL;
    struct node *temp = createNode(postArr[postIndex]);
    postIndex--;

    if(inStart == inEnd)
        return temp;

    int inIndex = searchIn(inArr,temp -> data,inStart,inEnd);
    temp -> right = constructBT(inArr,postArr,inIndex+1,inEnd);
    temp -> left = constructBT(inArr,postArr,inStart,inIndex-1);

    return temp;
};

void printPre(struct node * root)
{
    if(root == NULL)
        return;

    printPre(root -> left);
    printPre(root -> right);
    printf("%c ",root -> data);
}

int main ()
{
    char postArr[] = {'D','E','B','F','C','A'};
    char inArr[] = {'D','B','E','A','F','C'};

    int length = sizeof(inArr) / sizeof(inArr[0]);

    struct node * root = constructBT(inArr,postArr,0,length -1);

    printPre(root);


}
