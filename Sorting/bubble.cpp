#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {4, 1, 5, 2, 3};
    int n = sizeof(a) / sizeof(a[0]); 

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
