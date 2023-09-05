#include <bits/stdc++.h>
#define _testHong_ 1
using namespace std;
typedef long long ll;
int main()
{
    
    multiset<int> mset;
    mset.insert(1);
    mset.insert(7);
    mset.insert(2);
    for(auto p:mset){
        cout<<p<<'\n';
    }
    auto it = mset.lower_bound(2);
    ll b[6];
    b[1] = *it, it++;
    b[2] = *it, it++;
    cout<<_testHong_;
    return 0;
}