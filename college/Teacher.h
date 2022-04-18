#ifndef _Teacher_h_
#define _Teacher_h_ 1

#include "CollegePerson.h"
#include <string>
#include <vector>
using namespace std;

class Teacher:virtual public CollegePerson
{
    public:
        Teacher();
        //newName, newGender, NewPhoneNumber为基类CollegePerson初始化
        //传入NewDepartment, NewSalary, NewTCourses为department，salary，TCourse初始化
        Teacher(const string& newName, const Gender& newGender, const string& newPhoneNumber,
                const string NewDepartment, const float NewSalary, const vector<string> NewTCourses);
        ~Teacher();
        // const Teacher& operator=(const Teacher& obj);
    private:
        string department; //部门
        float salary; //工资 默认为零 salary>=0
        vector<string> tCourses; //所授课程
    public:
        string getDepartment(){return this->department;};
        float getSalary(){return this->salary;};
        vector<string> getTCourses(){return this->tCourses;};
};

#endif