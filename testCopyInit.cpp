#include <iostream>
using namespace std;

class testCopyInit
{
private:
    int num;
public:
    testCopyInit(/* args */);
    testCopyInit(const testCopyInit& obj);
    ~testCopyInit();
};

testCopyInit::testCopyInit(/* args */)
{
}

testCopyInit::~testCopyInit()
{
}
