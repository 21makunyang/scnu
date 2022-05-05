#ifndef _SALESMAN_H_
#define _SALESMAN_H_

#include "Employee.h"
#include <string>
using namespace std;
class SalesMan: public Employee
{
    public:
        SalesMan();
        SalesMan(unsigned int newId, const string& newName, const float newSales);
        ~SalesMan();
    private:
        float sales;
    public:
        float makeSalary();
};

#endif