#include<iostream>
using namespace std;
class B{
     public:
	       B();
	       B(int i);
	       ~B();
	       void Print() const;
     private:
	       int b;
};
B::B()
{	b=0;
	cout<<"B's default constructor called."<<endl;
}
B::B(int i)
{	b=i;
    cout<<"B's constructor called." <<endl;
}
B::~B()
{	cout<<"B's destructor called."<<endl;  }
void B::Print() const
{	cout<<b<<endl;  }
class C:public B
{
    public:
      C();
	  C(int i,int j);
	  ~C();
	  void Print() const;
	private:
	  int c;
};
C::C() //:B()
{	c=0;
	cout<<"C's default constructor called."<<endl;
}
C::C(int i,int j):B(i)
{	c=j;
	cout<<"C's constructor called."<<endl;
}
C::~C()
{	cout<<"C's destructor called."<<endl; }
void C::Print() const
{	B::Print();	cout<<c<<endl;  }
int main()
{	C obj(5,6);	obj.Print();  }
