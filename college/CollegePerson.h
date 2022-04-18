#ifndef _CollegePerson_h_
#define _CollegePerson_h_ 1

#include <string>
#include <vector>
using namespace std;

enum Gender
{
    unknow,
    male,
    female
};

class CollegePerson{
    public:
        CollegePerson();
        CollegePerson(const string& newName, const Gender& newGender, const string& newPhoneNumber);
        ~CollegePerson();
        // virtual const CollegePerson& operator=(const CollegePerson& obj);
    private:
        string name; //姓名
        Gender gender; //性别 男（male）或女（female）
        string phoneNumber; //电话号码
    public:
        string getName(){return this->name;};
        Gender getGender(){return this->gender;};
        string getPhoneNumber(){return this->phoneNumber;};
};
#endif