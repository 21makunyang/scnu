#include <iostream>
#include <thread>
using namespace std;

void threadObj(int n,int m)
{
    cout<<"hello threadId "<<n<<' '<<m<<endl;
    return ;
}

int main()
{
    thread th1(threadObj,3);
    th1.join();
    return 0;
}