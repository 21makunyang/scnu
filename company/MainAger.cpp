#include "MainAger.h"

float MainAger::makeSalary()
{
    return 8000;
}
MainAger::MainAger()
{
    setSalary( makeSalary() );
}

MainAger::MainAger(unsigned int newId, const string& newName):Employee(newId, newName)
{
    setSalary( makeSalary() );
}
