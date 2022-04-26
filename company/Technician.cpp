#include "Technician.h"

Technician::Technician(){}

Technician::~Technician(){}

float Technician::makeSalary()
{
    return this->workHour*100;
}

Technician::Technician(unsigned int newId, const string& newName, const float newWorkHour):
                        Employee(newId, newName)
{
    this->workHour = newWorkHour;
    this->salary = makeSalary();
}