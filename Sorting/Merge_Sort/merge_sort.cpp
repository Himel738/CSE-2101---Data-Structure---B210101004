#include<bits/stdc++.h>
using namespace std;

void merging(vector<int> &a,int low,int mid,int high)
{
    int left_size = (mid - low) + 1;
    int right_size = high - mid;

    vector<int>list1;
    vector<int>list2;

    for(int i = 0; i < left_size; i++)
    {
        list1.push_back(a[low+i]);
    }
    for(int j = 0; j < right_size; j++)
    {
        list2.push_back(a[mid+1+j]);
    }

    int i=0,j=0,k=low;

    while(i < left_size && j < right_size)
    {
        if(list1[i] <= list2[j])
        {
            a[k] = list1[i];
            i++;
        }
        else
        {
            a[k] = list2[j];
            j++;
        }
        k++;
    }

    while(i < left_size)
    {
        a[k] = list1[i];
        i++;
        k++;
    }

    while(j < right_size)
    {
        a[k] = list2[j];
        j++;
        k++;
    }

}

void merge_sort(vector<int> &a,int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;

        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);

        merging(a,low,mid,high);
    }

}

void print(vector<int>a)
{
    for(int  i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main ()
{
    int n;
    cin >> n;
    vector<int>a(n);

    for(int i=0; i < n; i++)
    {
        cin >> a[i];
    }

    merge_sort(a,0,n-1);
    print(a);
}