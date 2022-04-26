#ifndef _Employee_h_
#define _Employee_h_ 1

#include <string>
using namespace std;
class Employee
{
    public:
        Employee();
        Employee(unsigned int newId, const string& newName);
        ~Employee();
    protected:
        unsigned int id;
        string name;
        float salary;
    public:
        unsigned int getId(){ return id; };
        string getName(){ return name; };
        float getSalary(){ return salary; };
        float setSalary(float newSalary);
};

#endif 