#include <iostream>
#include <cmath>
#include <iomanip>

double fact(int digit)
{
    double result = 1;
    for (int i=digit; i>1; i--)
    {
        result *= i;
    }
    return result;
}

int main()
{
    long double pi = 0.0;
    int precision = 10;
    for ( int k=0; k<=precision; k++)
    {
        pi += ( pow(-1, k)*fact((6*k))*(13591409+545140134*k))/(fact(3*k)*pow(fact(k),3)*pow(640320, (3*k+1.5)));
    }
    pi = 1.0/(12*pi);
    std::cout<<std::setprecision(50)<<pi<<'\n'<<M_PI<<'\n';
}  
