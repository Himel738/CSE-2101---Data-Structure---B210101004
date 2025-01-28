#include<bits/stdc++.h>
using namespace std;

int main ()
{
    cout << "Enter The Number of Elemnts - ";
    int n;
    cin >> n;
    cout << endl;

    double a[n][n];

    for(int i  = 0; i < 1; i++)
    {
        for(int j = 0; j <n; j++)
        {
            cin >> a[i][j];
        }
    }
    int k= n-1;


    for(int i = 1; i < n; i++)
    {
        cout << "Del " << i << " " << endl;
        for(int j = 0; j < k; j++)
        {
            a[i][j] = a[i-1][j+1] - a[i-1][j];
            cout<< fixed << setprecision(6) << a[i][j] << endl;
        }
        k = k - 1;
    }

}