/* 1. it must not allow us to insert more than one root elements
   2. It Must check whether the parent node of the node we want to insert exist or not
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int index = -1;
char tree[MAX];

void root(char a)
{
    if(tree[0] != '\0')
    {
        printf("Root Already Exist\n");
    }
    else
        tree[0] = a;
}

void left(char a , int parent)
{
    if(tree[parent] == '\0')
    {
        printf("Can't insert %c. Parent of %c dosen't exist.\n",a,a);
    }
    else
    {
        tree[(2 * parent) + 1] = a;
    }
}

void right(char a , int parent)
{
     if(tree[parent] == '\0')
    {
        printf("Can't insert %c. Parent of %c dosen't exist.\n",a,a);
    }
    else
    {
        tree[(2 * parent) + 2] = a;
    }
}

void print ()
{
    for(int i = 0; i < MAX; i++)
    {
        if(tree[i] == '\0')
            printf("*");
        else
            printf("%c", tree[i]);
    }
}

int main ()
{
    root('A');
    left('B',0);
    right('C',0);
    left('D',1);
    right('E',1);
    print();

}
