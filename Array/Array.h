
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
	bool push_back(value_name value);
	iterator begin() { return myfirst; };
	iterator end() { return mylast; };
	Array<value_name>& operator=(Array<value_name>& obj);
	bool mySort();
	bool showAll();
	void insert(unsigned int index,T value);
	T at(unsigned int index);
	bool find(T taeget);
	void erase(unsigned int index);
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