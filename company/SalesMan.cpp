#include "SalesMan.h"

float SalesMan::makeSalary()
{
    return 0.04*this->sales;
}
SalesMan::SalesMan(){}

SalesMan::~SalesMan(){}

SalesMan::SalesMan(unsigned int newId, const string& newName, const float newSales):
                    Employee(newId, newName)
{
    this->sales = newSales;
    this->salary = makeSalary();
}