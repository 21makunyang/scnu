#ifndef _Student_h_
#define _Student_h_ 1

#include "CollegePerson.h" 
using namespace std;
class Student:virtual public CollegePerson
{
    public:
        Student();
        //newName, newGender, NewPhoneNumber为基类CollegePerson初始化
        //传入NewSCourses ，NewGrade为SCourses，grade初始化
        Student(const string& newName, const Gender& newGender, const string& newPhoneNumber,            
                const vector<string>& newSCourses,const vector<float>& results, const string newGrade); 
        ~Student();
        //const Student& operator =(const Student& obj);
    private:
        vector<string> sCourses;  //专业课程 
        vector<float> results; //成绩列表 默认为-1
        string grade; //年级 
    public:
        string getGrade(){return this->grade;};
        vector<string> getSCourses(){return this->sCourses;};
        vector<float> getResults(){return results;};
};
#endif 