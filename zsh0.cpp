#include<bits/stdc++.h>
#include "Calculator.h"
int main()
{
    int level_up_exp[10]={10,10,30,50,50,50,100,150,150,200};
    srand(time(NULL));
    int mode;
    int level=0,exp=0;
    FILE *fp=fopen("file.txt","r");
    fscanf(fp,"%d %d",&level,&exp);
    fclose(fp);
    while(1)
    {
        printf("欢迎使用小学运算练习器!\n");
        pro_type_in:printf("请选择功能:\n(1)普通练习模式\n(2)游戏模式\n(3)退出\n");
        scanf("%d",&mode);
        if(mode==3)
        {
            printf("再见~\nGoodBye~\nさよなら~\n");
            fp=fopen("file.txt","w");
            fprintf(fp,"%d %d",level,exp);
            fclose(fp);
            return 0;
        }
        else if(mode==1)
        {
            int exer_num,count=0;
            bool re=0;
            printf("请输入需要练习的题数:");
            scanf("%d",&exer_num);
            printf("提示:除法运算若带小数需保留小数点后两位\n");
            for(int i=0;i<exer_num;i++)
            {
                re=calc_2();
                if(re)
                {
                    count++;
                    printf("Correct!\n");
                }
                else printf("Wrong!\n");
            }
            float cor_rate=(float)count/exer_num;
            printf("本次练习正确%d道,错误%d道,正确率为%.0f%%\n",count,exer_num-count,cor_rate*100);
        }
        else if(mode==2)
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
                re=calc_2();
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
        else
        {
            printf("请重新输入\n");
            goto pro_type_in;
        }
        printf("按回车键继续...");
        std::cin.get();
        std::cin.get();
        system("clear");
    }
    return 0;
}