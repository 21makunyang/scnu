#include<iostream>
// #include "stdafx.h"
#include "Reader.h"
#include <cstring>
#include <iomanip>
using namespace std;

// const int Maxbor=5;//最大借阅量
Reader::Reader(){}
Reader::~Reader(){}
char *Reader::getname()
{return name;}
int Reader::getnote()
{return note;}
int Reader::getnumber()
{return number;}
void Reader::setname(char na[])
{strcpy(name,na);}
void Reader::addreader(int n,char *na)
{
	note=0;
	number=n;
	strcpy(name,na);
	for(int i=0;i<Maxbor;i++)
		borbook[i]=0;
}
void Reader::delbook()
{note=1;}
void Reader::borrowbook(int bookid)
{
	for(int i=0;i<Maxbor;i++)
	{
		if(borbook[i]==0)
		{
			borbook[i]=bookid;
			cout<<"借书成功！"<<'\n';
			return;
		}
		cout<<"借书失败!已达最大借阅量!"<<'\n';
	}
}
int Reader::retbook(int bookid)
{
	for(int i=0;i<Maxbor;i++)
	{
		if(borbook[i]==bookid)
		{
			borbook[i]=0;
			cout<<"还书成功！"<<'\n';
			return 1;
		}
		cout<<"还书失败！"<<'\n';
	}
	return 0;
}
void Reader::list()
{
	cout<<setw(5)<<number<<setw(10)<<name<<"借书编号: [";
	for(int i=0;i<Maxbor;i++) if(borbook[i]!=0) cout<<borbook[i]<<" ";
	cout<<"]"<<endl;
}