#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long seed, n, a[maxn];
long long nextRand()
{
    static long long x = seed;
    x ^= x << 11;
    x ^= x >> 45;
    x ^= x << 14;
    return (x % n + n) % n;
}
long long f(long long num){
    long long sum=0;
    for(long long i=0;i<n;i++){
        sum+=a[i]^(num*i);
    }
    return sum%n;
}
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> seed;
    for (int i = 0; i < n; ++i)
    {
        a[i] = nextRand();
    }
    long long num[n];
    for(int i=0;i<n;i++)
        num[i] = -1;
    for(long long i=0;i<n;i++){
        if(num[f(i)]>=0)
        {
        //     cout<<num[f(i)]<<" "<<i<<'\n';
        //    // return 0;
        cout<<num[f(i)]<<" "<<i;
            return 0;
        }
        else{
            num[f(i)] = i;
        }
    }
    return 0;
}