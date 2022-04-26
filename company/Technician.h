#ifndef _TECHNICIAN_H_
#define _TECHNICIAN_H_

#include "Employee.h"

class Technician:public Employee
{
    public:
        Technician();
        Technician(unsigned int newId, const string& newName, const float newSales);
        ~Technician();
    private:
        float workHour;
    public:
        float makeSalary();
};

#endif