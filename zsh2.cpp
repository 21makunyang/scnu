//更新日志:
//1.0 将简单四则运算代码实现并入复杂四则运算代码 缩短代码长度
//2.0 将各功能函数集成 加入注释
//3.0 加入成就、设置系统
//3.1 更新更多用户数据 加入引继码
//3.2 修复生成引继码出现乱码的bug
#include<bits/stdc++.h>
#define QUES_NUM 10
int level_up_exp[10]={10,10,30,50,50,50,100,150,150,200};
class Calculator
{
    private:
    int level;  //等级
    int exp;  //经验
    int Game_Mode_Correct_Count;
    int Game_Mode_Wrong_Count;
    int Problem_Exercise;
    int Award_Num;
    bool Award_Complete[12];
    public:
    Calculator();
    bool Calc(bool);
    void Game_Mode();
    void Exer_Mode(bool);
    bool Type_In_Data();
    bool Store_Data();
    void Award();
    void Settings();
    char *Encode();
    void Decode(char[]);
    bool Is_Wrong_Code(char[]);
};
Calculator::Calculator()
{
    level=0;
    exp=0;
    Game_Mode_Correct_Count=0;
    Game_Mode_Wrong_Count=0;
    Problem_Exercise=0;
    Award_Num=0;
    Award_Complete[12]={0};
}

inline void System_Pause()  //暂停
{
    printf("按回车键继续...");
    std::cin.get();
    std::cin.get();
    system("clear");
}

bool Calculator::Type_In_Data()  //读取数据
{
    FILE *fp=fopen("file.txt","r");
    if(fp==NULL)
    {
        fp=fopen("file.txt","w+");
        fprintf(fp,"0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0");
        fclose(fp);
        fp=fopen("file.txt","r");
    }
    fscanf(fp,"%d %d %d %d %d",&level,&exp,&Game_Mode_Correct_Count,&Game_Mode_Wrong_Count,&Problem_Exercise);
    for(int i=0;i<12;i++) fscanf(fp,"%d",&Award_Complete[i]);
    fscanf(fp,"%d",&Award_Num);
    fclose(fp);
    return 1;
}

bool Calculator::Calc(bool Easy_Flag=0)  //计算
{
    int num_n;
    if(!Easy_Flag) num_n=rand()%4+3;
    else num_n=2;
    float answer,result=0;
    std::vector<int>op(num_n-1);
    std::vector<float>num(num_n);
    for(int i=0;i<num_n-1;i++) op[i]=rand()%4+1;
    if(op[0]==3) num[0]=rand()%100;
    else num[0]=rand()%1000;
    for(int i=1;i<num_n;i++)
    {
        if(op[i-1]==1||op[i-1]==2) num[i]=rand()%1000;
        else if(op[i-1]==3) num[i]=rand()%100;
        else
        {
            do
            {
                num[i]=rand()%100;
            }
            while(num[i]==0);
        }
    }
    for(int i=0;i<num_n-1;i++)
    {
        switch(op[i])
        {
            case 1:
            {
                printf("%.0f+",num[i]);
                break;
            }
            case 2:
            {
                printf("%.0f-",num[i]);
                break;
            }
            case 3:
            {
                printf("%.0f×",num[i]);
                break;
            }
            case 4:
            {
                printf("%.0f÷",num[i]);
                break;
            }
        }
    }
    printf("%.0f= ",num[num_n-1]);
    float re_temp;
    bool calc_flag=0;
    for(int i=0;i<num_n-1;)
    {
        calc_flag=0;
        if(op[i]==3)
        {
            re_temp=num[i]*num[i+1];
            calc_flag=1;
            num_n--;
        }
        else if(op[i]==4)
        {
            re_temp=num[i]/(num[i+1]*1.0);
            re_temp=round(re_temp*100)/100;
            calc_flag=1;
            num_n--;
        }
        if(calc_flag==0) i++;
        else
        {
            num.erase(num.begin()+i+1);
            op.erase(op.begin()+i);
            num[i]=re_temp;
        }
    }
    for(int i=0;i<num_n-1;)
    {
        if(op[i]==1) re_temp=num[i]+num[i+1];
        else re_temp=num[i]-num[i+1];
        num.erase(num.begin()+i+1);
        op.erase(op.begin()+i);
        num[i]=re_temp;
        num_n--;
    }
    result=num[0];
    scanf("%f",&answer);
    if(answer==result) return 1;
    else return 0;
}
void Calculator::Exer_Mode(bool Easy_Flag=0)  //练习模式
{
    int exer_num,count=0;
    bool re=0;
    printf("请输入需要练习的题数: ");
    scanf("%d",&exer_num);
    printf("提示:除法运算若带小数需保留小数点后两位\n");
    for(int i=0;i<exer_num;i++)
    {
        re=Calc(Easy_Flag);
        if(re)
        {
            count++;
            printf("Correct!\n");
        }
        else printf("Wrong!\n");
    }
    float cor_rate=(float)count/exer_num;
    printf("本次练习正确%d道,错误%d道,正确率为%.0f%%\n",count,exer_num-count,cor_rate*100);
    System_Pause();
}
void Calculator::Game_Mode()  //游戏模式
{
    printf("提示:游戏模式将不在每题结束后提示正确与否\n了解请按回车键...\n");
    std::cin.get();
    std::cin.get();
    system("clear");
    if(level>=10) printf("当前等级:%d 当前经验:%d 恭喜你已满级!\n",level,exp);
    else printf("当前等级:%d 当前经验:%d 离升级还差:%d\n",level,exp,level_up_exp[level]-exp);
    printf("提示:除法运算若带小数需保留小数点后两位\n");
    int count=0;
    bool re=0;
    for(int i=0;i<QUES_NUM;i++)
    {
        re=Calc();
        if(re) count++;
    }
    int cor_rate=count*QUES_NUM;
    printf("本次游戏正确%d道,错误%d道,正确率为%d%%\n获得经验%d\n",count,QUES_NUM-count,cor_rate,cor_rate/QUES_NUM);
    exp+=cor_rate/QUES_NUM;
    while(level<10&&exp>=level_up_exp[level])
    {
        printf("恭喜你升到了%d级\n",level+1);
        exp-=level_up_exp[level];
        level++;
    }
}

bool Calculator::Store_Data()  //保存数据
{
    FILE *fp=fopen("file.txt","w");
    fprintf(fp,"%d %d %d %d %d\n",level,exp,Game_Mode_Correct_Count,Game_Mode_Wrong_Count,Problem_Exercise);
    for(int i=0;i<12;i++) fprintf(fp,"%d ",Award_Complete[i]);
    fprintf(fp,"%d",Award_Num);
    fclose(fp);
    return 1;
}
void Calculator::Award()
{
    printf("游戏模式累计正确10道题");
    printf("游戏模式累计正确50道题");
    printf("游戏模式累计正确200道题");
    printf("游戏模式累计错误10道题");
    printf("游戏模式累计错误50道题");
    printf("游戏模式累计错误200道题");
    printf("累计完成题目50道");
    printf("累计完成题目200道");
    printf("累计完成题目500道");
    printf("等级达到3级");
    printf("等级达到7级");
    printf("等级达到10级");
}
void Calculator::Settings()  //设置
{
    int Set_Mode;
    while(1)
    {
        system("clear");
        Settings_Mode_Type_In:;
        printf("请选择功能:\n(1)个人数据统计\n(2)重置数据\n(3)恢复数据\n(4)生成引继码\n(5)退出设置\n");
        scanf("%d",&Set_Mode);
        if(Set_Mode==1)
        {
            system("clear");
            printf("等级: %d级\n",level);
            printf("经验: %d点\n",exp);
            printf("游戏模式累计正确题数: %d题\n",Game_Mode_Correct_Count);
            printf("游戏模式累计错误题数: %d题\n",Game_Mode_Wrong_Count);
            printf("总练习题数: %d题\n",Problem_Exercise);
            printf("累计获得成就数: %d个\n",Award_Num);
            System_Pause();
        }
        else if(Set_Mode==2)
        {
            system("clear");
            printf("你确定要这么做吗?\n这将会使数据消失很长一段时间!\n(1)确定\n(0)取消\n");
            int Del_Data_Flag=0;
            scanf("%d",&Del_Data_Flag);
            if(Del_Data_Flag)
            {
                FILE *fp=fopen("file.txt","w");
                fprintf(fp,"0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0");
                fclose(fp);
                Type_In_Data();
                printf("重置成功!\n");
                return;
            }
        }
        else if(Set_Mode==3)
        {
            system("clear");
            printf("请输入引继码: ");
            char *CODE=new char[16];
            scanf("%s",CODE);
            Decode(CODE);
            delete[] CODE;
            printf("恢复数据成功!\n");
            System_Pause();
        }
        else if(Set_Mode==4)
        {
            system("clear");
            char *CODE=new char[16];
            CODE=Encode();
            printf("引继码为: %s\n请妥善保管!\n",CODE);
            delete[] CODE;
            System_Pause();
        }
        else if(Set_Mode==5) return;
        else
        {
            printf("请重新输入\n");
            goto Settings_Mode_Type_In;
        }
    }
}

char *Calculator::Encode()
{
    char *CODE=new char[16];
    if(level<10) CODE[0]=char(level+48);
    else
    {
        if(rand()%2) CODE[0]='x';
        else CODE[0]='X';
    }
    CODE[3]=char(exp/100+'0');
    CODE[2]=char((exp-exp/100*100)/10+'0');
    CODE[1]=char(exp%10+'0');
    for(int i=0;i<12;i++)
    {
        int Rand=rand()%2;
        int Letter=rand()%18+1;
        if(Rand) CODE[i+4]=char((Letter*2-Award_Complete[i])+65);
        else CODE[i+4]=char((Letter*2-Award_Complete[i])+97);
    }
    return CODE;
}
void Calculator::Decode(char CODE[])
{
    if(Is_Wrong_Code(CODE))
    {
        printf("引继码错误!\n");
        system("sleep 1");
        return;
    }
    if(CODE[0]<='9'&&CODE[0]>='0') level=CODE[0]-'0';
    else level=10;
    exp=100*(CODE[3]-'0')+10*(CODE[2]-'0')+(CODE[1]-'0');
    for(int i=0;i<12;i++)
    {
        if(CODE[i+4]%2==0&&CODE[i+4]!=96&&CODE[i+4]<='z'&&CODE[i+4]>='A')
        {
            Award_Complete[i]=1;
            Award_Num++;
        }
        else if(CODE[i+4]%2==1&&CODE[i+4]!=96&&CODE[i+4]<='z'&&CODE[i+4]>='A')
        {
            Award_Complete[i]=0;
        }
    }
}
bool Calculator::Is_Wrong_Code(char CODE[])
{
    bool Is_Wrong=0;
    if(!(CODE[0]=='x'||CODE[0]=='X'||(CODE[0]<='9'&&CODE[0]>='0'))) Is_Wrong=1;
    if(CODE[1]>'9'&&CODE[1]<'0'||CODE[2]>'9'&&CODE[2]<'0'||CODE[3]>'9'&&CODE[3]<'0') Is_Wrong=1;
    for(int i=0;i<12;i++) if(!(CODE[i+4]!=96&&CODE[i+4]<='z'&&CODE[i+4]>='A')) Is_Wrong=1;
    if(Is_Wrong) return 1;
    else return 0;
}

int main()
{
    printf("┌——————————————————————————————┐\n");
    printf("|                              |\n");
    printf("|   欢迎使用小学运算练习器!    |\n");
    printf("|                              |\n");
    printf("└——————————————————————————————┘\n");
    srand(time(NULL));
    int mode;
    Calculator Pupil;
    Pupil.Type_In_Data();
    system("sleep 2");
    system("clear");
    while(1)
    {
        pro_type_in:;
        printf("请选择功能:\n(1)普通练习模式\n(2)游戏模式\n(3)设置\n(4)退出\n");
        scanf("%d",&mode);
        if(mode==4)
        {
            printf("再见~\n");
            Pupil.Store_Data();
            return 0;
        }
        else if(mode==1)
        {
            exer_mode_type_in:;
            system("clear");
            printf("请选择难度:\n(1)简单四则运算\n(2)混合四则运算\n(3)退出\n");
            int exer_mode_num;
            scanf("%d",&exer_mode_num);
            if(exer_mode_num==1) Pupil.Exer_Mode(1);
            else if(exer_mode_num==2) Pupil.Exer_Mode();
            else if(exer_mode_num==3) return;
            else
            {
                printf("请重新输入\n");
                system("sleep 1");
                system("clear");
                goto exer_mode_type_in;
            }
        }
        else if(mode==2) Pupil.Game_Mode();
        else if(mode==3) Pupil.Settings();
        else
        {
            printf("请重新输入\n");
            system("sleep 1");
            system("clear");
            goto pro_type_in;
        }
        //System_Pause();
    }
    return 0;
}