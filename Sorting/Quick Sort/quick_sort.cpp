#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[],int low,int high)
{
    int pivot = a[high];
    int i = low - 1;

    for(int j  = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a[j],a[i]);
        }
    }
    
    i++;
    swap(a[i],a[high]);

    return i;
}

void quick_sort(int a[], int low,int high)
{
     if(low < high)
     {
        
        int pivotindex = partition(a,low,high);
        //print(a,5);
        quick_sort(a,low,pivotindex-1);
        print(a,5);
        quick_sort(a,pivotindex+1,high);
        print(a,5);
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

    quick_sort(a,0,n-1);
    //print(a,n);
}