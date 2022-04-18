#include "CollegePerson.h"

CollegePerson::CollegePerson(){
    this->gender = unknow;
}

CollegePerson::~CollegePerson(){}

CollegePerson::CollegePerson(const string& newName, const Gender & newGender, const string& newPhoneNumber)
{
    this->name = newName;
    this->gender = newGender;
    this->phoneNumber = newPhoneNumber;
}
// const CollegePerson& CollegePerson::operator=(const CollegePerson& obj)
// {
//     if(this == &obj) return *this;
//     this->name = obj.name;
//     this->gender = obj.gender;
//     this->phoneNumber = obj.phoneNumber;
//     return *this;
// }