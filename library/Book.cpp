#include<iomanip>
// #include "stdafx.h"
#include "Book.h"
#include <string.h>
using namespace std;
char *Book::getname()
{return name;}
int Book::getnote()
{return note;}
int Book::getnumber()
{return number;}
void Book::setname(char na[])
{strcpy(name,na);}
void Book::addbook(int n,char *na)
{
	note=0;
	number=n;
	strcpy(name,na);
	onshelf=1;
}
void Book::delbook()
{note=1;}
int Book::borrowbook()
{return onshelf;}
void Book::retbook()
{onshelf=1;}
void Book::list()
{cout<<setw(5)<<number<<setw(10)<<name<<setw(10)<<onshelf<<endl;}
