#include "Student.h"

Student::Student(){}

Student::~Student(){}

Student::Student(const string& newName, const Gender& newGender, const string& newPhoneNumber,
                 const vector<string>& newSCourses,const vector<float>& results, const string newGrade):CollegePerson(newName,newGender,newPhoneNumber)
{
    this->sCourses = newSCourses;
    this->results = results;
    this->grade = newGrade;
}

// const Student& Student::operator=(const Student& obj)
// {
//     this->SCourses = obj.SCourses;
//     this->results = obj.results;
//     this->grade = obj.grade;
//     return *this;
// }