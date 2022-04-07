#include "CAcount.h"
void CAcount::operator=(const CAcount& obj)
{
    this->id = obj.id;
    if(this->name != nullptr)
    {
        this->name[0]='\0';
        delete[] this->name;
    }
    this->name = new char[strlen(obj.name)+1];
    if(this->name != nullptr) strcpy(this->name,obj.name);
    this->account = obj.account;
    return;
}
CAcount::CAcount()
{
    this->id = 0;
    this->name = nullptr;
    this->account = 0.0;
}
CAcount::CAcount(const char name[],int id=1,float account=0.0) //一定要用const char[]或const char*,要么用string，用char*实际传入一个字符，char[]不接受字符串常量
{
    this->id = id;
    this->name = new char[strlen(name)+1];
    if(this->name!=nullptr) strcpy(this->name,name);
    this->account=account;
}

CAcount::CAcount(const CAcount & a)
{
    this->id = a.id;
    this->name = new char[strlen(a.name)+1];
    if(this->name!=nullptr) strcpy(this->name,a.name);
    this->account=a.account;
}

CAcount::~CAcount()
{
    if(this->name!=nullptr)
    {
        this->name[0] = '\0';
        delete[] name;
    }
    this->id=0;
    this->account =0.0;
}

void CAcount::showData()
{
    cout<<this->id<<'\n';
    if(this->name != nullptr) cout<<this->name<<'\n';
    else cout<<"null"<<'\n';
    cout<<this->account<<"\n\n";
    return;
}

