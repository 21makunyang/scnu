#include <bits/stdc++.h>
using namespace std;
int n, x,maxBag;
vector<int> a(n);

int ans = 0;
void traceBack(int cur, int index)
{
    if (cur>maxBag){
        return;
    }
    ans = max(cur,ans);

    if (index >= n)
    {
        // if (cur >= x)
        // {
        //     ans = min(ans, cur);
        // }
        return;
    }
    // ans = max(cur,ans);
    
    traceBack(cur + a[index], index + 1);
    traceBack(cur, index + 1);
}
bool cmp(int x, int y){
    return x>y;
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
    sort(a.begin(), a.end(),cmp);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    maxBag = sum - x;
    
    traceBack(0, 0);
    printf("%d", sum -ans);
    return 0;
}