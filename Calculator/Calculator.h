#ifndef _Calculator_h_
#define _Calculator_h_ 1
class Calculator
{
private:
    int level;
    int exp;
public:
    int symbol;
    Calculator(){
        level=0;
        exp=0;
    };
    int print(int,int);
    int topic();
    bool judge();
    int mode2();
    int mode1();
    int display();
    int mode2Plus();
    char createSign(int);
};
char getCommand(char,char);
int getNum();
void pause();
#endif
