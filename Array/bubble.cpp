#include<bits/stdc++.h>
using namespace std;

void bubble(int *a,int n)
{

    int flag=0;
    for(int i =0; i < n-1; i++)
    {
        flag=0;

        for(int j = i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                flag=1;
            }
        }
        if(flag==0)
            {
                break;
            }
    }
    for(int i=0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int main ()
{
    int n;
    cin >> n;

    int *a = (int *) malloc (n * sizeof(int));

    for(int i=0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble(a,n);
}
