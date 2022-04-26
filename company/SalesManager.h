#ifndef _SALSEMANAGER_H_
#define _SALSEMANAGER_H_

#include <string>
#include "Employee.h"
class SalesManager: public Employee
{
    public:
        SalesManager();
        SalesManager(unsigned int newId, const string& newName, const float newSales);
        ~SalesManager();
    private:
        float sales;
    public:
        float makeSalary();
};


#endif