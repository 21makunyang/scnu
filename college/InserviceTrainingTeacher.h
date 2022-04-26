#ifndef _InserviceTrainingTeacher_h_
#define _InserviceTrainingTeacher_h_ 1

#include "Student.h"
#include "Teacher.h"
class InserviceTrainingTeacher:public Student, public Teacher
{
    public:
        InserviceTrainingTeacher();
        //newName, newGender, NewPhoneNumber为基类CollegePerson初始化
        //传入NewSCourses ，NewGrade为SCourses，grade初始化
        //传入NewDepartment, NewSalary, NewTCourses为department，salary，TCourse初始化
        InserviceTrainingTeacher(
            const string& newName, const Gender& newGender, const string& newPhoneNumber,            
            const vector<string>& newSCourses, const vector<float>& results, const string newGrade,
            const string NewDepartment, const float NewSalary, const vector<string> NewTCourses); //直接在后面加const即可
        ~InserviceTrainingTeacher();

};
#endif