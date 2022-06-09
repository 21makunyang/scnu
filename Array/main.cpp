#include "Array.h"
#include <iostream>
#include "Array.cpp" //类模板要把.cpp包含进来
using namespace std;


typedef Array<int>* LP_int;
typedef Array<float>* LP_float;
typedef Array<bool>* LP_bool;
int isCreated = 0;
int main()
{
	Array<int> intArr;
	Array<bool> boolArr;
	Array<float> floatArr;
	//void *arr = nullptr;
	while (1) {
		int oper;
		cout << "*------------------------------------------* \n";
		cout << "|                                          | \n";
		cout << "|            欢迎来到数组操作库            | \n";
		cout << "|                                          | \n";
		cout << "*------------------------------------------* \n";
		cout << "|                请选择操作：              | \n";
		cout << "|                1.生成数组                | \n";
		cout << "|                2.数组排序                | \n";
		cout << "|                3.元素插入                | \n";
		cout << "|                4.元素查找                | \n";
		cout << "|                5.元素删除                | \n";
		cout << "|                6.数组输出                | \n";
		cout << "|            7.输出指定位置元素            | \n";
		cout << "|                  0.退出                  | \n";
		cout << "*------------------------------------------* \n";
		cin >> oper;
		

		if (0 == oper)
		{
			break;
		}

		else if (1 == oper)
		{
			if (isCreated == 1)
			{
				cout << "已创建数组\n";
				continue;
			}
			cout << "请选择数组类型：\n";
			cout << "1.整型\n";
			cout << "2.浮点型\n";
			cout << "3.布尔型\n";
			cin >> isCreated;
			if(1 == isCreated) create(isCreated,intArr);
			else if(2 == isCreated) create(isCreated,floatArr);
			else create(isCreated,boolArr);
			//cout<<(*((LP_int)arr)).begin()<<'\n';
		}

		else if (2 == oper) {
			if (isCreated == 0)
			{
				cout << "数组未创建\n";
				cout << "请创建数组\n";
				continue;
			}
			if (1 == isCreated)
			{
				intArr.mySort();
				cout<<"排序完成\n";
			} 
			else if (2 == isCreated)
			{
				floatArr.mySort();
				cout<<"排序完成\n";
			}
			else {
				cout<<"排序完成\n";
				continue;
			}
		}

		else if(3 == oper)
		{
			int index; 
			cout<<"请输入插入位置：\n";
			cin>>index;
			cout<<"请输入插入元素：\n";
			if(1 == isCreated)
			{
				int value;
				cin>>value;
				intArr.insert(index,value);
			}
			else if(2 == isCreated)
			{
				float value;
				cin>>value;
				intArr.insert(index,value);
			}
			else if (1 == isCreated)
			{
				bool value;
				cin>>value;
				intArr.insert(index,value);
			}
			cout<<"插入成功\n";
		}

		else if(4 == oper)
		{
			if (isCreated == 0)
			{
				cout << "数组未创建\n";
				cout << "请创建数组\n";
				continue;
			}
			cout<<"请输入查找元素：\n";
			if (1 == isCreated){
				int target;
				cin>>target;
				intArr.find(target);
			} 
			else if (2 == isCreated) 
			{
				float target;
				cin>>target;
				floatArr.find(target);
			}
			else if (3 == isCreated)
			{
				bool target;
				cin>>target;
				boolArr.find(target);
			}
			else continue;
		}
		else if(5 == oper)
		{
			if (isCreated == 0)
			{
				cout << "数组未创建\n";
				cout << "请创建数组\n";
				continue;
			}
			cout<<"请输入删除元素下标：\n";
			if (1 == isCreated){
				int target;
				cin>>target;
				intArr.erase(target);
			} 
			else if (2 == isCreated) 
			{
				float target;
				cin>>target;
				floatArr.erase(target);
			}
			else if (3 == isCreated)
			{
				bool target;
				cin>>target;
				boolArr.erase(target);
			}
			else continue;
			cout<<"删除成功\n";
		}
		else if(6 == oper)
		{
			if (isCreated == 0)
			{
				cout << "数组未创建\n";
				cout << "请创建数组\n";
				continue;
			}
			//if (isCreated == 1) 
			if (1 == isCreated) intArr.showAll();
			else if (2 == isCreated) floatArr.showAll();
			else if (3 == isCreated) boolArr.showAll();
			else continue;
		}

		else if(7 == oper)
		{
			if (isCreated == 0)
			{
				cout << "数组未创建\n";
				cout << "请创建数组\n";
				continue;
			}
			cout<<"请输入查找元素下标：\n";
			unsigned int index;
			cin>>index;
			if (1 == isCreated) intArr.at(index);
			else if (2 == isCreated) floatArr.at(index);
			else if (3 == isCreated) boolArr.at(index);
			else continue;
		}
		
	}
	return 0;
}