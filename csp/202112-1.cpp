#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,N,num;
    cin>>n>>N;
    vector<int> budget(N,{0});
    for (int i = 1; i <= n; i++)
    {
        cin>>num;
        budget[num] = i;
    }
    int i = 0,tem = 0,j=0;
    long long sum=0;
    while (i<=N)
    {
        while(i<N && budget[i]==0){
            i++;
        }
        sum+=tem*(i-j);
        j=i;
        tem=budget[i];
        i++;
    }
    cout<<sum<<'\n';
    return 0;
}