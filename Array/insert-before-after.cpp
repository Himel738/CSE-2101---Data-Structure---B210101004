#include<stdio.h>
#include<stdlib.h>

void before(int * a, int * n)
{
  *n = (*n + 1);
   a = (int *)realloc(a,(*n)*sizeof(int));

   int count = 0;

   int value;
   printf("Enter Your Value,before You Want To Insert-");
   scanf("%d",&value);

   int value1;
   printf("Enter Your Value1,Which one You Want To Insert-");
   scanf("%d",&value1);

   for(int i = 0; i < *n; i++)
   {
       if(count==1)
       {
           break;
       }
       if(a[i]==value)
       {
           for(int j = (*n-1); j >=i-1; j-- )
           {
               a[j] = a[j-1];

               if(j==(i))
               {
                   a[j] = value1;
                   count=1;
                   break;
               }
           }
       }
   }
   for(int i = 0; i < *n; i++)
   {
       printf("%d ",a[i]);

       if(i==(*n-1))
       {
           printf("\n");
       }
   }
}
void after (int * a,int * n)
{
   *n = (*n + 1);
   a = (int *)realloc(a,(*n)*sizeof(int));

   int count = 0;

    int value;
   printf("Enter Your Value,After You Want To Insert-");
   scanf("%d",&value);

   int value1;
   printf("Enter Your Value1,Which one You Want To Insert-");
       scanf("%d",&value1);


   for(int i = 0; i < *n; i++)
   {
       if(count==1)
       {
           break;
       }
       if(a[i]==value)
       {
           for(int j = (*n-1); j >=i+1; j-- )
           {
               a[j] = a[j-1];

               if(j==(i+1))
               {
                   a[j] = value1;
                   count=1;
                   break;
               }
           }
       }
   }



   for(int i = 0; i < *n; i++)
   {
       printf("%d ",a[i]);

       if(i==(*n-1))
       {
           printf("\n");
       }
   }
}
void insert(int * a,int * n)
{
    *n = (*n + 1);
   a = (int *)realloc(a,(*n)*sizeof(int));

   int index;
   printf("Enter Your Index-\n");
   scanf("%d",&index);

   int value;
   printf("Enter Your Value-\n");
   scanf("%d",&value);

   for(int i = (*n-1); i >=index; i--)
   {
       a[i] = a[i-1];

       if(i == index)
       {
           a[i] = value;
           break;
       }
   }
   for(int i = 0; i < *n; i++)
   {
       printf("%d ",a[i]);

       if(i==(*n-1))
       {
           printf("\n");
       }
   }
}
int main ()
{
   int n;
   scanf("%d",&n);

   int *a = (int *) malloc(n * sizeof(int));

   for(int i = 0; i < n; i++)
   {
       scanf("%d",&a[i]);
   }
   insert(a,&n);
   after(a,&n);
   before(a,&n);
}
