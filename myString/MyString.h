#include <cstddef>
class MyString
{
    public:
        MyString();//默认str为空，长度为零
        MyString(const char* c);//用字符串初始化
        MyString(const char c[],int size);//用字符串c的前size个字符初始化
        MyString(const MyString& s); //拷贝构造函数
        ~MyString();
        const MyString& operator=(const MyString &obj); // =号运算符重载
    private:
        int len;
        char* str; //字符串指针
    public:
        static const size_t npos;
        char* getStr(){return this->str;};
        MyString &Strcpy(const MyString &s1); //用s1给当前mystring赋值
        void append(MyString &s); //将s连接在后面
        void assign(const char c[]); //把字符串c赋值给当前字符串
        unsigned long length();//返回mystring类字符串长度
        unsigned long find(char ch);//在mystring中寻找ch返回位置号,未找到返回npos
        void showMyString(); //输出字符串到屏幕
        void Swap(MyString& s1,MyString& s2);//交换两个字符串
};