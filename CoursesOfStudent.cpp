#include "CoursesOfStudent.h"

CoursesOfStudent::CoursesOfStudent(){}

CoursesOfStudent::~CoursesOfStudent(){}

CoursesOfStudent::CoursesOfStudent(const vector<string>& NewCourses,const vector<float>& NewResults)
{
    // for(int i = 0; i<NewCourses.size(); i++)
    // {
        this->courses = NewCourses;
        this->results = NewResults;
    // }
}

CoursesOfStudent::CoursesOfStudent(const string & NewCourse,const float NewResult)
{
    this->courses.push_back(NewCourse);
    this->results.push_back(NewResult);
}

// const CoursesOfStudent& CoursesOfStudent::operator=(const CoursesOfStudent& obj)
// {
//     this->courses = obj.courses;
//     this->results = obj.results;
//     return *this;
// }