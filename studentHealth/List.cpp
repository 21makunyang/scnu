#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

void StudentList::createList()
{
	stuList = new Student[1];
	len = 0;
	cap = 1;
}
istream& operator>>(istream& input, Student& obj)
{
	input >> obj.id;
	input >> obj.name;
	int tem;
	input >> tem;
	if(tem == 0)
		obj.gender = male;
	else if(tem==1)
		obj.gender =female;
	input >> obj.birthday;
	input >> obj.health;
	return input;
}
ostream& operator<<(ostream& output, const Student& obj)
{
	output << obj.id << " ";
	output << obj.name << " ";
	output << obj.gender << " ";
	output << obj.birthday << " ";
	output << obj.health <<'\n';
	return output;
}

void StudentList::insert(Student& stu)
{
	if (len == cap)
	{
		unsigned int i = 0;
		Student* tem = new Student[cap * 2];
		cap = cap * 2;
		for ( i = 0; i < len; i++)
		{
			tem[i] = stuList[i];
		}
		delete[] stuList;

		len++;
		tem[i] = stu;
		
		stuList = tem;
		tem = nullptr;
		return;
	}
	
	len++;
	stuList[len - 1] = stu;
	return;
}

void StudentList::save()
{
	ofstream out("data.txt", ios::out);
	for (unsigned int i = 0; i < len; i++)
	{
		out << stuList[i];
	}
	out.close();
	return;
}



Student StudentList::createStu()
{
	Student stu;
	cout << "please input student's id:\n";
	cin >> stu.id;

	cout << "please input student's name:\n";
	cin >> stu.name;

	cout << "please input student's gender:\n";
	string str;
	cin >> str;
	if (str == "male")
		stu.gender = male;
	else if (str == "female")
		stu.gender = female;

	cout << "please input student's birthday:\n";
	cin >> stu.birthday;

	cout << "please input student's health:\n";
	cin >> stu.health;
	return stu;
}

void StudentList::getData()
{
	ifstream in("data.txt", ios::in);
	while (!in.eof())
	{
		Student stu;
		in >> stu.id;
		in >> stu.name;
		int tem;
		in >> tem;
		if (tem == 0)
			stu.gender = male;
		else if (tem == 1)
			stu.gender = female;
		in >> stu.birthday;
		in >> stu.health;
		insert(stu);
	}
	in.close();
	return;
}

void StudentList::show()
{
	for (unsigned int i = 0; i < len; i++)
		cout <<i<<" " << stuList[i]<<'\n';
	return;
}

void StudentList::deleteStu(unsigned int sId)
{
	if (len  < 1 / 4 * cap)
	{
		Student* tem = new Student[1/2*cap];
		unsigned int i=0;
		bool exist =false;
		while (i<len)
		{
			cout << i << '\n';
			i++;
			if (stuList[i].id == sId) {
				exist = true;
				break;
			}
			tem[i] = stuList[i];
		}

		if (exist == false)
		{
			cout << "student doesn't exist.";
			return;
		}
		
		while (i < len) {
			tem[i] = stuList[i + 1];
			i++;
		}

		delete[] stuList;
		stuList = tem;
		tem = nullptr;
		len--;
		return;
	}

	unsigned int i=0;
	bool exist = false;
	while (i < len)
	{
		i++;
		if (stuList[i].id == sId) {
			exist = true;
			break;
		}
	}
	if (exist == false)
	{
		cout << "student doesn't exist.";
		return;
	}
	while (i < len) {
		stuList[i] = stuList[i + 1];
		i++;
	}
	len--;
	return;
}

StudentList::StudentList()
{
	createList();
	getData();
}

StudentList::~StudentList()
{
	save();
	len = 0;
	if (stuList != nullptr)
	{
		delete[] stuList;
	}
}


