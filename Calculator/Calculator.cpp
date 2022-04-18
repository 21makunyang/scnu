#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include "Calculator.h"
using namespace std;

char getCommand(char left,char right)
{/*进行输入合法性判断，若ASCII码小于left或大于right则重新输入，返回合法指令*/
    char command;
    while(1){
        cin>>command;
        if(command<left || command>right)
        {
            cout<<"输入非指定命令，请重新输入"<<'\n';
        }
        else break;
    }
    return command;
}
int getNum()
{/*进行输入合法性判断，若不是数字则重新输入，返回合法数字*/
    char num;
    while(1){
        cin>>num;
        if(isdigit(num))
        {
            break;
        }
        else cout<<"输入非指定数字，请重新输入"<<'\n';
    }
    return num-'0';
}
void pause()//用于linux环境下暂停程序和清屏，使用户界面更清晰
{
    cout<<"请按回车键继续..."<<'\n';
    cin.get();
    cin.get();
    system("clear");
    return;
}
int Calculator::display(){//游戏模式下展示当前等级和经验
    printf("当前您的等级：%d\n",level);
    printf("升级还需经验：%d\n",(level+1)-exp);
    return 1;
}
char Calculator::createSign(int tem) //传入一个随机数tem来生成符号
{
    if(tem==0) return '+'; //等于0，则为“+”号
    if(tem==1) return '-'; //等于1，则为“-”号
    if(tem==2) return '*'; //等于2，则为“*”号
    if(tem==3) return '/'; //等于3，则为“/”号
    return ' ';
}
int Calculator::print(int a,int b)//传入两个参数，a和b进行格式化打印
{
    if(b<0) printf("%d %c (%d) =",a,createSign(symbol),b);//若b为负数则加上括号打印
    else printf("%d %c %d =",a,createSign(symbol),b);//若b不是负数则直接输出
    return 1;
}
int Calculator::topic() //生成题目，返回正确答案ans
{
    re2:
    int a=rand()%1000*pow(-1,rand()%2); //生成运算数 -999~999
    int b=rand()%1000*pow(-1,rand()%2); //生成运算数 -999~999
    symbol=rand()%4;        //生成运算符的代表符号 1:'+'    2:'-'   3:'*'  4:'/'  
    int ans=0;   //用于计算正确答案，一开始为0
    if(symbol==0){
        ans=a+b;
        print(a,b);
    }
    else if(symbol==1){
        ans=a-b;
        print(a,b);
    }
    else if(symbol==2){
        ans=a*b;
        print(a,b);
    }
    else{
        if(b==0) goto re2; //若b==0且作为除数，则重新生成算式
        ans=a/b;
        print(a,b);
    }
    return ans;
}
bool Calculator::judge() //判断答案是否正确，正确返回true，否则返回false
{
    int ans=topic();
    int ansOfStu;
    ansOfStu=getNum();
    return (ans==ansOfStu);
}
int Calculator::mode2()//简单练习模式
{
    if(judge())
    {
        cout<<"correct!\n";
    }
    else{
        cout<<"wrong,try again~\n";
    }
    cout<<'\n';
    return 1;
}
int Calculator::mode1() //游戏模式
{
    display();
    if(judge()) //答案正确则获得经验：加法1点，减法2点，乘法3点，除法4点，错误则没有
    {
        cout<<"correct!\n";
        cout<<"获得经验："<<symbol+1<<'\n';
        pause();
        exp+=symbol+1;
    }
    else{
        cout<<"wrong,try again~\n";
        pause();
    }
    if(exp>=(level+1)*2)//总经验超过当前等级+1的两倍则升级
    {
        while(exp>=(level+1)*2)
        {
            exp-=(level+1)*2;
            level++;
        }
        cout<<"恭喜升级!\n";
        cout<<"当前等级："<<level<<'\n';
    }
    printf("\n距离升级还需经验：%d\n",(level+1)*2-exp);
    return 1;
}
int Calculator::mode2Plus() //四则运算，执行成功返回1
{
    int number=rand()%1000*pow(-1,rand()%2); //生成运算数 -999~999
    stack<int> oper;  //用于计算，先算乘除，后算加减
    vector<int> sign;
    vector<int> num;
    int count=1,numOfNum=0,tem; //count统计插入的运算数个数，tem为
    while(numOfNum<2) //运算数总个数，至少两个，最多5个
    {
        numOfNum=rand()%6;
    }
    num.push_back(number);//将运算数存起来，以便输出
    oper.push(number);  //将运算数进栈，用于计算
    while(count<numOfNum)
    {
        re3:
        count++;
        number=rand()%1000*pow(-1,rand()%2);  //生成新运算数 -999~999
        tem=rand()%4;   //生成运算符
        sign.push_back(tem); 
        if(tem<2)//如果是加减法，先不计算，先存起来
        {
            oper.push(number);
            num.push_back(number);
        }
        else{
            if(tem==2)  //乘法
            {
                num.push_back(number);
                number=number*oper.top();
            }
            else{  //除法
                if(number==0) goto re3; //若b==0且作为除数，则重新生成算式
                num.push_back(number);
                number=oper.top()/number;
            }
            oper.pop();
            oper.push(number);
        }
    }
    for(count=0;count<numOfNum-1;count++) //数字符号间隔输出，数字为负数则加入括号
    {
        if(num[count]<0) cout<<'('<<num[count]<<") ";
        else cout<<num[count]<<' ';
        cout<<createSign(sign[count])<<' ';
    }
    if(num[count]<0) cout<<'('<<num[count]<<") ";
    else cout<<num[count]<<' ';
    cout<<'=';
    count=0;
    while(oper.size()!=1)
    {
        while(sign[count]>1) count++; //跳过乘除法
        number=oper.top();
        oper.pop();
        if(sign[count]==0) number+=oper.top(); //加法
        else number = oper.top()-number;  //减法
        oper.pop();
        oper.push(number);
    }
    int ansOfStu;
    ansOfStu=getNum();
    if(ansOfStu==oper.top()) //判断答案是否正确
    {
        cout<<"correct!\n";
    }
    else{
        cout<<"wrong,try again~\n";
    }
    cout<<'\n';
    return 1;
}