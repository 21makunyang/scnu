#include "Manager.h"

float Manager::makeSalary()
{
    return 8000;
}
Manager::Manager()
{
    setSalary( makeSalary() );
}

Manager::Manager(unsigned int newId, const string& newName):Employee(newId, newName)
{
    setSalary( makeSalary() );
}

Manager::~Manager(){}