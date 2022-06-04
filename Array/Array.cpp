#include "Array.h"
#include <iostream>
extern Array<int> intArr;
extern Array<bool> boolArr;
extern Array<float> floatArr;

typedef Array<int> *LP_int;
typedef Array<float> *LP_float;
typedef Array<bool> *LP_bool;

using namespace std;
template <typename T>
Array<T>::Array()
{
	myfirst = nullptr;
	mylast = nullptr;
	myend = nullptr;
	len = 0;
}

template <typename T>
Array<T>::Array(unsigned int length)
{
	myfirst = new T[length];
	mylast = myfirst;
	myend = myfirst + length;
	len = 0;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &obj)
{
	this->myfirst = new T[obj.len];
	for (int i = 0; i < obj.len; i++)
	{
		myfirst[i] = obj.myfirst[i];
	}
	this->mylast = this->myfirst + obj.len;
	this->myend = this->myfirst + obj.len;
	this->len = obj.len;
	return *this;
}

template <typename T>
bool Array<T>::push_back(T value)
{
	if (myfirst == nullptr)
	{
		T *tem = new T[5];
		this->myfirst = tem;
		this->mylast = this->myfirst;
		this->myend = this->myfirst + 5;
	}
	else if (myend == mylast)
	{
		unsigned int oldLen = this->len;
		T *tem = new T[oldLen * 2];
		for (unsigned int i = 0; i < oldLen; i++)
		{
			tem[i] = this->myfirst[i];
		}
		delete[] this->myfirst;
		this->myfirst = tem;
		this->mylast = this->myfirst + oldLen;
		this->myend = this->myfirst + oldLen * 2;
	}
	*mylast = value;
	len++;
	// cout<<len<<'\n';
	mylast++;
	return 1;
}

template <typename T>
Array<T>::~Array()
{
	if (myfirst != nullptr)
	{
		delete[] myfirst;
	}
}

template <typename T>
bool Array<T>::mySort()
{
	unsigned int isSortedIndex = 0;
	unsigned int current = 1;
	T tem;
	while (isSortedIndex != this->len)
	{
		current = isSortedIndex + 1;
		if (current >= this->len)
		{
			break;
		}
		while ((myfirst[current] < myfirst[current - 1]) && current != 0)
		{
			tem = myfirst[current];
			myfirst[current] = myfirst[current - 1];
			myfirst[current - 1] = tem;
			current--;
		}
		isSortedIndex++;
	}
	return 1;
}

template <typename T>
bool Array<T>::showAll()
{
	if (this->myfirst == nullptr)
	{
		cout << "empty\n";
		return 0;
	}
	for (int i = 0; i < this->len; i++)
	{
		cout << this->myfirst[i] << ' ';
	}
	cout << '\n';
	return 1;
}

template <typename T>
inline int create(int &isCreated, Array<T> &arr)
{
	cout << "请输入数组长度:\n";
	int len;
	cin >> len;
	cout << "请输入数组元素:\n";
	if (1 == isCreated)
	{
		int input;
		for (int i = 0; i < len; i++)
		{
			cin >> input;
			arr.push_back(input);
		}
		return 1;
	}
	if (2 == isCreated)
	{
		float input;
		for (int i = 0; i < len; i++)
		{
			cin >> input;
			arr.push_back(input);
		}
		return 2;
	}
	else if (3 == isCreated)
	{
		bool input;
		for (int i = 0; i < len; i++)
		{
			cin >> input;
			arr.push_back(input);
		}
		return 3;
	}
	return 0;
}

template <typename T>
void Array<T>::insert(unsigned int index, T value)
{
	if (index >= this->len)
	{
		if (myend == mylast)
		{
			unsigned int oldLen = this->len;
			T *tem = new T[oldLen * 2];
			for (unsigned int i = 0; i < oldLen; i++)
			{
				tem[i] = this->myfirst[i];
			}
			delete[] this->myfirst;
			this->myfirst = tem;
			this->mylast = this->myfirst + oldLen;
			this->myend = this->myfirst + oldLen * 2;
		}
		*mylast = value;
		len++;
		mylast++;
		return;
	}
	unsigned int i = 0;
	if (myend == mylast)
	{
		unsigned int oldLen = this->len;
		this->len++;
		T *tem = new T[oldLen * 2];
		delete[] this->myfirst;
		this->myfirst = tem;
		this->mylast = this->myfirst + oldLen;
		this->myend = this->myfirst + oldLen * 2;
		for (i = 0; i < index; i++)
		{
			tem[i] = this->myfirst[i];
		}
		tem[i] = value;
		for (unsigned int i = index + 1; i < oldLen + 1; i++)
		{
			tem[i] = this->myfirst[i - 1];
		}
		return;
	}
	len++;
	T tem = myfirst[len];
	for (i = len; i >index; i--)
	{
		this->myfirst[i] = this->myfirst[i - 1];
	}
	this->myfirst[i] = value;
}

template<typename T>
T Array<T>::at(unsigned int index)
{
	if(index>=this->len)
	{
		cerr<<"数组越界\n";
		return NULL;
	}
	return this->myfirst[index];
}

template<typename T>
bool Array<T>::find(T taeget)
{
	for(unsigned int i = 0;i<this->len;i++)
	{
		if(this->myfirst[i] == taeget)
		{
			cout<<"查找元素下标为："<<i<<'\n';
			return 1;
		}
	}
	cout<<"未找到元素"<<'\n';
	return 0;
}

template<typename T>
void Array<T>::erase(unsigned int index)
{
	for(unsigned int i = index;i<this->len;i++)
	{
		this->myfirst[i] = this->myfirst[i+1];
	}
	// this->mylast--;
	this->len--;
	this->mylast = this->myfirst +(len -1);
	return;
}