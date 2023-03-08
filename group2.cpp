#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //定义优先队列 
    priority_queue<int ,vector<int>,greater<int> >que;
    long long k;
    long long  sum=0;
    for(int i=1;i<=n;i=i+1)
    {
        cin>>k;
        que.push(k);
    }

    while(!que.empty())
    {
        long long a1=que.top();
        que.pop();
        if(que.empty())
        {
            break;
        }
        long long a2=que.top();
        long long a3=a1+a2;
        sum=sum+a3;
        que.push(a3);
        que.pop();
    }
    cout<<sum;
}