#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>
using namespace std;
class Complex
{
private:
    double real;
    double imag;
public:
    // Complex();
    Complex(double r = 0.0, double i= 0.0);
    ~Complex();
    friend istream& operator>>(istream& input, Complex& obj);
    friend ostream& operator<<(ostream& output, const Complex & obj);
    const Complex& operator=(const Complex& obj);
};

#endif