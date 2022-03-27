#include <cmath>
#include <iostream>
using namespace std;
#define e 0.000001
template<unsigned int N>
double NthRoot(double d, double lower, double upper){
    double mid = lower + (upper - lower) / 2;
    double multiply = mid;
    for(int i = N; i > 1; i --){
        multiply *= mid;
    }

    double diff = multiply - d;
    
    if(abs(diff) <= e){
        return mid;
    }

    if(diff > e){
        return NthRoot<N>(d, lower, mid);
    }
    else {
        return NthRoot<N>(d, mid, upper);
    }
}

double cubicRoot(double d){
    if (d < 0)
        return 0;

    if (d < 1)
    {
        return NthRoot<3>(d, d, 1);
    }

    return NthRoot<3>(d, 1, d);
}

double squareRoot(double d){
    if (d < 0)
        return 0;

    if (d < 1)
    {
        return NthRoot<2>(d, d, 1);
    }

    return NthRoot<2>(d, 1, d);
}

int main()
{
    double d = 8;
    cout << d << ", cubicRoot: " << cubicRoot(d) << ", squareRoot: " << squareRoot(d) << "\n";

    d = 0.001;
    cout << d << ", cubicRoot: " << cubicRoot(d) << ", squareRoot: " << squareRoot(d) << "\n";
    return 0;
}