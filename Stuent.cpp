#include <bits/stdc++.h>
using namespace std;
typedef struct Student{
    char name[20];
    int id;
    char gender[5];
    int cScore;
    int mathScore;
    int comScore;
}Student,*LPStudent;
void input(LPStudent student)
{
    /**/
    cout<<"请输入该学生姓名:\n";
    cin>>student->name;
    cout<<"请输入该学生学号:\n";
    cin>>student->id;
    cout<<"请输入该学生性别:\n";
    cin>>student->gender;
    cout<<"请输入该学生C语言成绩:\n";
    cin>>student->cScore;
    cout<<"请输入该学生数学成绩:\n";
    cin>>student->mathScore;
    cout<<"请输入该学生计算机导论成绩:\n";
    cin>>student->comScore;
    return;
}
void output();