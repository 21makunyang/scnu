#include <bits/stdc++.h>
using namespace std;
int n, x, maxBag;
vector<int> a(n);
map<int, int> buy;
int ans = 0;
void traceBack(int cur, int index)
{
    if (cur > maxBag)
    {
        return;
    }
    ans = max(cur, ans);

    if (index >= n)
    {
        // if (cur >= x)
        // {
        //     ans = min(ans, cur);
        // }
        return;
    }
    // ans = max(cur,ans);
    if (buy.find(a[index]) != buy.end()&& buy[a[index]]!=0)
    {
        buy[a[index]]--;
        traceBack(cur, index + 1);
    }else{
        traceBack(cur + a[index], index + 1);
        traceBack(cur, index + 1);
    }
    
    
}
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &x);
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int idx;
        scanf("%d", &idx);
        buy[a[idx]]++;
    }
    int sum = 0, hadtobuy = 0;
    for (int i = 0; i < n; i++)
    {

        sum += a[i];
    }
    for(auto elem:buy){
        sum-=elem.first*elem.second;
        hadtobuy+=elem.first*elem.second;
    }
    sort(a.begin(), a.end(), cmp);
    

    if (hadtobuy >= x)
    {
        printf("%d\n", hadtobuy);
        return 0;
    }
    else
    {
        x -= hadtobuy;
    }
    maxBag = sum - x;

    traceBack(0, 0);
    printf("%d\n", sum - ans + hadtobuy);
    return 0;
}