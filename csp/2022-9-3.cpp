#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

set<LL> sd[1025], su;
struct node
{
    LL d, u, r;
}a;

vector<node> v[1025];
LL n, ri, mi, d, u, r, pi;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
    {
        cin >> ri >> mi;
        
        for (int j = 0; j < ri; j ++ ) 
        {
            cin >> pi;
            for (int k = i; k < i + 7; k ++ ) sd[k].insert(pi);
        }
        
        for (int j = 0; j < mi; j ++ ) // 
        {
            cin >> d >> u >> r;
            if (d < 0) continue;
            if (!sd[d].count(r)) continue; 
            v[i].push_back({d, u, r});
        }
        
        for (int j = max(0, i - 6); j <= i; j ++ )
        {
            for (int k = 0; k < v[j].size(); k ++ )
            {
                d = v[j][k].d;
                u = v[j][k].u;
                r = v[j][k].r;
                bool flag = 1;
                if (d <= i - 7) continue; 
                for (int l = d; l <= i; l ++ ) 
                    flag = flag & sd[l].count(r);
                if (flag) su.insert(u);
            }
        }
        
        cout << i << " ";
		for (auto it : su) cout << it << " ";
		cout << endl;
		su.clear();
    }
    
    return 0;
}
