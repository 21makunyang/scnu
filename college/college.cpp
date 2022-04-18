#include "CollegePerson.h"
#include "Student.h"
#include "Teacher.h"
#include "Worker.h"
#include "InserviceTrainingTeacher.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<string> sCour{"math","computer"};
    vector<float> sRes{1,2.5};
    InserviceTrainingTeacher itt("mky", male, "12345678900", sCour,sRes,"grade 1","cs",0.1,sCour);
    cout<<"name:"<<itt.getName()<<'\n';
    cout<<"gender:"<<itt.getGender()<<'\n';
    cout<<"phonenumber:"<<itt.getPhoneNumber()<<'\n';
    cout<<"sCourse:"<<itt.getSCourses()[1]<<'\n';
    cout<<"results:"<<itt.getResults()[1]<<'\n';
    cout<<"grade:"<<itt.getGrade()<<'\n';
    cout<<"deparrtment:"<<itt.getDepartment()<<'\n';
    return 0;
}