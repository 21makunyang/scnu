#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    scanf("%d",&n);
    double sum=0.0;
    double D=0.0,avg;
    vector<double> nums(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&nums[i]);
        sum+=nums[i];
    }
    avg = sum/double(n);
    for (int i = 0; i < n; i++)
    {
        D+=1.0/double(n)*(nums[i]-avg)*(nums[i]-avg);
    }
    for (int i = 0; i < n; i++)
    {
       printf("%lf ",(nums[i]-avg)/sqrt(D));
    }
    printf("\n");
    return 0;
}