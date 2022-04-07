#include "bank.h"
void output(CAcount& a)
{
    a.showData();
    return;
}

void outputAll(CAcount a[],int num)
{
    for(int i=0;i<num;i++)
    {
        a[i].showData();
    }
    return;
}
CAcount& reset(CAcount& a2,const CAcount &a1)
{
    a2 = a1;
    return a2;
}