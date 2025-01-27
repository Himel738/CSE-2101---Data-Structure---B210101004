#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (x*x*x) - (2 *x) - 5;
}

double bisection( double a,double b,double tolerance)
{
      

    while(1)
    {
    double currentmid = (a+b) / 2.0; //cout << currentmid << endl;

        if (f(currentmid) == 0 || abs(f(currentmid)) <= tolerance)
        {
            return currentmid;
        }
    
      if(f(currentmid) < 0)
      {
        a = currentmid;
      }
      if(f(currentmid) > 0)
      {
        b = currentmid;
      }
      //iteration++;
    }
    //return (a+b) / 2.0;
}

int main ()
{
    cout << "Enter The Interval- ";
    double a,b;
    cin >> a >> b;
    cout << endl;

    cout << "Enter The Tolerance - ";
    double tolerance;
    cin >> tolerance;
    cout << endl;

    double KutuMia = bisection(a,b,tolerance);

    cout << fixed << setprecision(4) << KutuMia << endl;

    
}