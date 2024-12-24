#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void selection_sort(int a[],int n)
{
    int i,j;
    for( i = 0; i < n-1; i++)
    {
        int smallindex = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[smallindex])
            {
                smallindex=j;
            }
        }

        swap(a[i],a[smallindex]);
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

    selection_sort(a,n);
    print(a,n);
}