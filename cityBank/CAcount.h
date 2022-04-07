#include <string.h>
#include <iostream>
using namespace std;
class CAcount
{
    public:
        CAcount(); //默认name为空，id=0，account=0.0
        CAcount(const char name[],int id,float account);//传入name,id,account对当前对象进行初始化 
        CAcount(const CAcount &); //传入一个对象对当前对象进行初始化
        ~CAcount();
        void operator=(const CAcount&); 
    private:
        int id; //账号 id>0
        char* name; //储户姓名
        float account; //储户余额
    public:
        void showData(); //展示当前对象信息,若name为空，输出null
        friend CAcount &reset(CAcount&a2,const CAcount&a1); //用用户a1给用户a2赋值，返回用户a2
        
};
