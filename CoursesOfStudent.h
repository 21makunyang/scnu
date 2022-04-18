#ifndef _CourseOfStudent_h_
#define _CourseOfStudent_h_ 1

#include <string>
#include <vector>
using namespace std;
class CoursesOfStudent
{
    public:
        CoursesOfStudent();
        CoursesOfStudent(const vector<string>& NewCourses,const vector<float>& NewGrades);
        CoursesOfStudent(const string & NewCourse,const float NewGrade);
        ~CoursesOfStudent();
        //const CoursesOfStudent& operator=(const CoursesOfStudent& obj);
    private:
        vector<string> courses;  //专业课程 
        vector<float> results; //成绩列表 默认为-1
    public:
        vector<string> getCourses(){return this->courses;};
        vector<float> getResults(){return this->results;};
};

#endif