#include "Employee.h"

Employee::Employee()
{}

Employee::~Employee()
{}

Employee::Employee(unsigned int newId, const string& newName)
{
    this->id = newId;
    this->name = newName;
}
float Employee::setSalary(float newSalary)
{
    this->salary = newSalary;
    return this->salary;
}