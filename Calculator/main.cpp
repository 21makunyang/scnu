#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
    srand(time(NULL));
    /*
      mode==1,游戏型
      mode==2,练习型
    */
    char mode; 
    Calculator user;
    while(1)  //使使用者能重复选择模式
    {
        cout<<"欢迎来到小学运算练习器!\n";
        cout<<"     请选择模式:\n";
        cout<<"     1.游戏型\n";
        cout<<"     2.简单练习型\n";
        cout<<"     0.退出\n";
        mode=getCommand('0','2');
        if(mode=='1'){
           char flag='1';   //用于判断是否继续游戏模式：1.继续 2退出该模式 其他，重新输入
            while(flag=='1'){
                system("clear");
                user.mode1();
                printf("是否继续?\n1.是\n2.否\n");
                flag=getCommand('1','2');
                system("clear");
            }
        }
        else if(mode=='2')
        {
            system("clear");
            int i,sum;
            cout<<"请选择难度:\n";
            cout<<"1.简单四则运算\n";
            cout<<"2.混合四则运算\n";
            mode=getCommand('1','2'); 
            cout<<"请输入题目数量:\n";
            sum=getNum();
            system("clear");
            for(i=0;i<sum;i++)
            {
                cout<<'('<<i+1<<") ";
                if(mode=='1')user.mode2();
                else user.mode2Plus();
                pause();
            } 
            printf("练习完成，你真棒!\n");
            system("sleep 1");
            system("clear");
        }
        else 
        {
            cout<<"下次再见!\n";
            break;
        }
    }
    return 0;
}