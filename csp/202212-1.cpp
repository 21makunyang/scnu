#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double i,earn,now =0.0,weight = 1.0;
    scanf("%d",&n);
    scanf("%lf",&i);
    for (int j = 0; j < n+1; j++)
    {
        scanf("%lf",&earn);
        now+=1.0/weight*earn;
        weight = weight*(1.0+i);
    }
    printf("%.3lf\n",now);
    return 0;
}