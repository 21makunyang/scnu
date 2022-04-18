#ifndef _Worker_h_
#define _Worker_h_ 1

#include "CollegePerson.h"
#include <string>
using namespace std;
class Worker: public CollegePerson
{
    public:
        Worker();
        Worker(
            const string& newName, const Gender& newGender, const string& newPhoneNumber,
            const string newWDpartment,const float newWSalary);
        ~Worker();
    private:
        string wDepartment;
        float wSalary; 
    public:
        string getWDepartment(){return this->wDepartment;};
        float getWSalary(){return this->wSalary;};
};

#endif