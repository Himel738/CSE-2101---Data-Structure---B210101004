#include<stdio.h>

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
    {
         if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 12;
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, N, x);
    if(result == -1)
    {
        printf("Element Is Not Present");
    }
    else
    {
        printf("Element Is Present");
    }

    return 0;
}
