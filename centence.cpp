#include <bits/stdc++.h>
using namespace std;
bool isNumber(char ch)
{
    if(ch<='9'&&ch>='0') return 1;
    else return 0;
}
int main()
{
    //freopen("test.in","r",stdin);
    int a=0,b=0,c=0;
    char x,ch;
    while(scanf("%c:=%c;",&x,&ch)!=EOF)
    {
        if(isNumber(ch))
        {
            if(x=='a')a=ch-'0';
            else if(x=='b')b=ch-'0';
            else if(x=='c')c=ch-'0';
        }
        else
        {
            if(x=='a')
            {
                if(ch=='b')a=b;
                if(ch=='c')a=c;
            }
            else if(x=='b')
            {
                if(ch=='a')b=a;
                if(ch=='c')b=c;
            }
            else if(x=='c')
            {
                if(ch=='b')c=b;
                if(ch=='a')c=a;
            }
        }
    }
    printf("%d %d %d",a,b,c);
    return 0;
}