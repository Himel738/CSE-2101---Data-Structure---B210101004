#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void insertion_sort(int a[],int n)
{
    
    for(int  i = 1; i < n; i++)
    {
        int current = a[i];
        int previous = i - 1;

        while(previous >=0 && a[previous] > current)
        {
            a[previous + 1] = a[previous];
            previous--;
        }

        a[previous+1] = current;
    }
}

int main ()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    insertion_sort(a,n);
    print(a,n);
}