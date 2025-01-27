#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (x*x*x) - (3*x) - 5.0;
}
double f_prime(double x)
{
    return (3*x*x) - 3;
}

double newton_raphson(double x0,int maxiteration)
{
    int iteration = 0;
    //set<double> Kutu;
    double x = x0,x_new;

    while(iteration <= maxiteration)
    {
         x_new = x - (f(x) / f_prime(x));

        if(x_new == x)
        {
            return x_new;
        }
        x = x_new;
        iteration++;
    }
    return x_new;


}

int main ()
{
    cout << "Enter The value Which is Closer to 0 for Function - ";
    int x0;
    cin >> x0;
    cout << endl;

    cout << "Enter The Iteration - ";
    int iteration;
    cin >> iteration;
    cout << endl;

    double KutuMia = newton_raphson(x0,iteration);

    cout << KutuMia << endl;
    
}