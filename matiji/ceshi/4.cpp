#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if(x==0&&y==0){
        cout<<0<<'\n';
        return 0;
    }
    int sum = abs(x) + abs(y);
    int cnt = 0;
    int contri = 0;
    for (int i = 0; i < sum - 1; i++)
    {
        contri += 4;
        cnt = contri + cnt;
    }
    int a = 1, b = sum - 1;
    cnt++;
    while ((a != x || b != y) && b > 0 && a < sum)
    {
        cnt++;
        a++;
        b--;
    }

    while ((a != x || b != y) && a > 0 && b > -sum)
    {
        cnt++;
        a--;
        b--;
    }
    while ((a != x || b != y) && a > -sum && b < 0)
    {
        cnt++;
        a--;
        b++;
    }
    while ((a != x || b != y) && b < sum && a < 0)
    {
        cnt++;
        a++;
        b++;
    }
    
    cout << cnt << '\n';
    return 0;
}