#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, x1, y1, x2, y2;
    int sum = 0;

    cin >> n >> a >> b;
    // vector<vector<bool>> area(a, vector<bool>(b, {0}));
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < 0)
        {
            x1 = 0;
        }
        if (y1 < 0)
        {
            y1 = 0;
        }
        //x 对应 a
        if (x2 > a)
        {
            x2 = a;
        }
        //y 对应 b
        if (y2 > b)
        {
            y2 = b;
        }
        if(x1>x2 || y1>y2){
            continue;
        }
        sum+=(x2-x1)*(y2-y1);
        
    }

    cout << sum<<'\n';
    return 0;
}