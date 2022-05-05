#ifndef _Manager_h_
#define _Manager_h_ 1

#include "Employee.h"
#include <string>
using namespace std;
class Manager:public Employee
{
    public:
        Manager();
        Manager(unsigned int newId, const string& newName);
        ~Manager();
        float makeSalary();
};

#endif