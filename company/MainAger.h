#ifndef _MainAger_h_
#define _MainAger_h_ 1

#include "Employee.h"
class MainAger:public Employee
{
    public:
        MainAger();
        MainAger(unsigned int newId, const string& newName);
        ~MainAger();
        float makeSalary();
};

#endif