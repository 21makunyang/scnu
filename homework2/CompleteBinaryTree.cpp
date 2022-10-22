#include <bits/stdc++.h>
using namespace std;
template <typename T,typename F>
void midOrder(int length,T CBT[],  F f)
{
    int i = 1;
    int stc[length];
    int top = -1;
    while(i<=length|| top!=-1){
        while(i <= length) 
        {
            stc[++top] = i;
            i*=2;
        }
    
        
        if (top!=-1){
            i=stc[top--];
            f(CBT[i-1]);
            i=i*2+1;
        }
    }
    
}
void f1(int data){
    cout<<data<<'\n';
    return ;
}
int main()
{
    int CBT[11];
    for (int i = 1; i < 12; i++)
    {
        CBT[i-1] = i;
    }
    function<void(int)> f = [=](int data){cout<<data<<'\n';};
    midOrder(11,CBT,f);
    return 0;
}