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
    int k = 1;


    for(int i = 1; i < n; i++)
    {
        cout << "Del " << i << " " << endl;
        for(int j = k; j < n; j++)
        {
            a[i][j] = a[i-1][j] - a[i-1][j-1];
            cout<< fixed << setprecision(6) << a[i][j] << endl;
        }
        k++;
    }

}