#ifndef _TECHNICIAN_H_
#define _TECHNICIAN_H_

#include "Employee.h"
#include <string>
using namespace std;
class Technician:public Employee
{
    public:
        Technician();
        Technician(unsigned int newId, const string& newName, const float workHour);
        ~Technician();
    private:
        float workHour;
    public:
        float makeSalary();
};

#endif