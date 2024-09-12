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

struct node *constructBT(char inArr[],char preArr[],int inStart,int inEnd)
{
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;
    struct node *temp = createNode(preArr[preIndex]);
    preIndex++;

    if(inStart == inEnd)
        return temp;

    int inIndex = searchIn(inArr,temp -> data,inStart,inEnd);
    temp -> left = constructBT(inArr,preArr,inStart,inIndex-1);
    temp -> right = constructBT(inArr,preArr,inIndex+1,inEnd);

     return temp;
};

void printPre(struct node * root)
{
    if(root == NULL)
        return;
    printf("%c ",root -> data);
    printPre(root -> left);
    printPre(root -> right);
}

int main ()
{
    char preArr[] = {'A','B','D','E','C','F','G','H'};
    char inArr[] = {'D','E','B','A','F','C','H','G'};

    int length = sizeof(inArr) / sizeof(inArr[0]);

    struct node * root = constructBT(inArr,preArr,0,length -1);

    printPre(root);


}
