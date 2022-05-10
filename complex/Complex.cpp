#include "Complex.h"

Complex::Complex(double r,double i)
{
    real = r;
    imag = i;
}

// Complex::Complex(/* args */)
// {
// }

Complex::~Complex()
{
}
istream& operator>>(istream& input, Complex& obj)
{
    input>>obj.real;
    input>>obj.imag;
    return input;
}
ostream& operator<<(ostream& output, const Complex & obj)
{
    output<<obj.real<<'\n';
    output<<obj.imag<<'\n';
    return output;
}
const Complex& Complex::operator=(const Complex& obj)
{
    this->real = obj.real;
    this->imag = obj.real;
    return *this;
}