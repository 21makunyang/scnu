
#ifndef _ARRAY_H_
#define _ARRAY_H_
template<typename T = int >
class Array
{
public:
	typedef T value_name;
	typedef value_name* iterator;
	Array();
	~Array();
	Array(unsigned int len);
private:
	iterator myfirst;
	iterator mylast;
	iterator myend;
	unsigned int len;

public:
	bool push_back(value_name value);//输入
	iterator begin() { return myfirst; };
	iterator end() { return mylast; };
	Array<value_name>& operator=(Array<value_name>& obj);
	bool mySort();
	bool showAll();
	void insert(unsigned int index,T value); //插入index位置，值为value
	T at(unsigned int index); //输出index位置元素
	bool find(T target); //查找
	void erase(unsigned int index);//删除
};
template<typename T>
inline int create(int & , Array<T>&);

extern Array<int> intArr;
extern Array<bool> boolArr;
extern Array<float> floatArr;

typedef Array<int>* LP_int;
typedef Array<float>* LP_float;
typedef Array<bool>* LP_bool;
#endif 

#include <vector>