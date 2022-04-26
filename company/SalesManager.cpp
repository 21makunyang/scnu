#include "SalesManager.h"

SalesManager::SalesManager(){}

SalesManager::~SalesManager(){}

float SalesManager::makeSalary()
{
    return 5000 + this->sales*0.05;
}

SalesManager::SalesManager(unsigned int newId, const string& newName, const float newSales):
                            Employee(newId, newName)
{
    this->sales = newSales;
    this->salary = makeSalary();
}