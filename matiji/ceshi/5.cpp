#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    vector<ll> nums(n), sum(n + 1);
    sum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum[i + 1] = sum[i] + nums[i];
    }
    // vector<int> cnt(sum[n] + 1,{0});
    map<int,int> dic;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dic[abs(sum[i]-sum[j])]++;
        }
    }
    int max = dic.begin()->second,maxI = dic.begin()->first;
    for(auto a: dic){
        if (max<a.second){
            max = a.second;
            maxI = a.first;
        }
    }
    cout<<max<<' '<< maxI<<'\n';
    return 0;
}