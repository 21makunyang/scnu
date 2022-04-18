#include "Worker.h"
Worker::Worker(){}

Worker::Worker(
    const string& newName, const Gender& newGender, const string& newPhoneNumber,
    const string newWDpartment,const float newWSalary):
    CollegePerson(newName, newGender, newPhoneNumber)
{
    this->wDepartment = newWDpartment;
    this->wSalary = newWSalary;
}

Worker::~Worker(){}