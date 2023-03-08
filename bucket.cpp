#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *heights = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>heights[i];
    }
    
    int l = 0, r = n - 1, lm = -1, rm = -1,ans=0;
    while (l < r)
    {
        if (lm < heights[l])
        {
            lm = heights[l];
        }
        if (rm < heights[r])
        {
            rm = heights[r];
        }
        if (lm < rm)
        {
            ans += lm - heights[l];
            l++;
        }
        else
        {
            ans += rm - heights[r];
            r--;
        }
    }
    cout<<ans<<'\n';
    delete[] heights;
     return 0;
}