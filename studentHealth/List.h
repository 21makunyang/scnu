#pragma once
#include "Student.h"
#include <iostream>
using namespace std;
class StudentList {
private:
	Student* stuList;
	unsigned int len;
	unsigned int cap;
	Student createStu();
public:
	StudentList();
	~StudentList();
	void createList();
	void insert(Student& stu);
	void save();
	void getData();
	void show();
	void deleteStu(unsigned int sId);

	friend istream& operator>>(istream & input, Student& obj);
	friend ostream& operator<<(ostream& output, const Student &obj);

	unsigned int getLen() { return len; }
	unsigned int getCap() { return cap; }
};

