class Calculator
{
private:
    int level;
    int exp;
public:
    int symbol;
    Calculator();
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
