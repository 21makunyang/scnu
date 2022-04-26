#include "InserviceTrainingTeacher.h"

InserviceTrainingTeacher::InserviceTrainingTeacher(){}

InserviceTrainingTeacher::~InserviceTrainingTeacher(){}

InserviceTrainingTeacher::InserviceTrainingTeacher(
    const string& newName, const Gender& newGender, const string& newPhoneNumber,            
    const vector<string>& newSCourses, const vector<float>& newResults, const string newGrade,
    const string newDepartment, const float newSalary, const vector<string> newTCourses):
    CollegePerson(newName, newGender, newPhoneNumber),
    Student(newName, newGender, newPhoneNumber, newSCourses, newResults, newGrade),
    Teacher(newName, newGender, newPhoneNumber, newDepartment, newSalary, newTCourses){}