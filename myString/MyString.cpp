#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;

const size_t MyString::npos=-1;

unsigned long MyString::length()
{
    return this->len;
}

MyString::MyString()//默认str为空，长度为零
{
    this->str=nullptr;
    this->len=0;
}

MyString::MyString(const char *c)//用字符串初始化
{
    int i,size;
    size=strlen(c); //计算c的长度
    this->len = size;
    str=new char[size];
    for(i=0;i<size;i++)
    {
        str[i]=c[i];
    }
}
MyString::MyString(const char c[],int size)//用字符串的前size个字符初始化
{
    this->len=size;
    int i;
    str=new char[size+1];
    for(i=0;i<size;i++)
    {
        str[i]=c[i];
    }
    str[i]='\0';
}

MyString::MyString(const MyString& s) //拷贝构造
{
    this->len = s.len;
    this->str= new char[s.len+1];
    if(this->str!= nullptr)
    {
        strcpy(this->str,s.str);
    }
}
MyString::~MyString()
{
    if(this->str!=nullptr){
        this->str[0]='\0';
        delete[] this->str;
        this->str=nullptr;
    }
    this->len=0;
}

MyString& MyString::Strcpy(const MyString & s1) //用s1给当前mystring赋值
{
    this->len=s1.len;
    if(this->str!=nullptr)
    {
        str[0]='\0';
        delete[] this->str;
    }
    str = new char[s1.len+1];
    if(this->str!=nullptr) strcpy(this->str,s1.str);
    return *this;
}
void MyString::append(MyString &s) //将s连接在后面
{
    MyString tem;
    int i;
    tem.len = this->len + s.len;
    tem.str = new char[tem.len+1];
    if(tem.str!= nullptr)
    {
        for(i=0;i<tem.len;i++)
        {
            if(i<this->len)
            {
                tem.str[i] = this->str[i];
            }
            else
            {
                tem.str[i] = s.str[i-this->len];
            }
        }
    }
    tem.str[i] = '\0';
    if(this->str!=nullptr)
    {
        this->str[0]='\0';
        delete[] this->str;
    }
    this->str = new char[tem.len+1];
    if(this->str!=nullptr)
    {
        strcpy(this->str,tem.str);
    }
    this->len = tem.len;
    return;
}

void MyString::assign(const char c[]) //把字符串c赋值给当前字符串
{
    int i;
    for(i=0;c[i+1]!='\0';i++);
    this->len = i-1;
    if(this->str!= nullptr)
    {
        this->str[0]='\0';
        delete[] this->str;
    }
    this->str = new char[this->len+1];
    if(this->str != nullptr) strcpy(this->str,c);
    return;
}

unsigned long MyString::find(char ch) //在mystring中寻找ch返回位置号,未找到返回npos
{
    int i;
    for(i=0;i<this->len;i++)
    {
        if(this->str[i] == ch)
        {
            return i;
        }
    } 
    return npos;
}

const MyString& MyString::operator=(const MyString& obj)
{
    this->len = obj.len;
    if(this->str != nullptr)
    {
        this->str[0]=0;
        delete[] this->str;
    }
    this->str = new char[this->len+1];
    if(this->str != nullptr) strcpy(this->str,obj.str);
    return *this;
}

void MyString::showMyString()  //输出字符串到屏幕
{
    cout<<this->str<<'\n';
    cout<<this->len<<'\n';
    return;
}
void MyString::Swap(MyString& s1,MyString& s2)//交换两个字符串
{
    MyString tem(s2);
    // tem.showMyString();
    // s1.showMyString();
    // s2.showMyString();
    // if(s2.str!=nullptr)
    // {
    //     s2.str[0]='\0';
    //     delete[] s2.str;
    // }
    // s2.str = new char[s1.len+1];
    // if(s2.str!=nullptr) strcpy(s2.str,s1.str);
    // if(s1.str!= nullptr)
    // {
    //     s1.str[0]='\0';
    //     delete[] s1.str;
    // }
    // s1.str = new char[tem.len+1];
    // if(s1.str!=nullptr) strcpy(s1.str,tem.str);
    // s1.showMyString();
    s2 = s1;
    s1 = tem;
    return;
}