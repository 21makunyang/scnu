#include "Teacher.h"

Teacher::Teacher()
{
    this->salary = 0;
}

Teacher::~Teacher(){}

Teacher::Teacher(
    const string& newName, const Gender& newGender, const string& newPhoneNumber,
    const string NewDepartment, const float NewSalary, const vector<string> NewTCourses):
    CollegePerson(newName, newGender, newPhoneNumber)
{
    this->department = NewDepartment;
    this->salary = NewSalary;
    this->tCourses = NewTCourses;
}

// const Teacher& Teacher::operator=(const Teacher& obj)
// {
//     if(this == &obj) return *this;
//     this->department = obj.department;
//     this->salary = obj.salary;
//     this->TCourses = obj.TCourses;
//     return *this;
// }