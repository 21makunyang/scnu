#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        int l = 0, r = 0;
        string nums = "1", temp = "";
        for (int i = 1; i < n; i++)
        {
            temp = "";
            l = r = 0;
            while (r < nums.length())
            {
                int cnt = 0;
                while (r < nums.length() && nums[r] == nums[l])
                    r++;
                cnt = r - l;
                temp += to_string(cnt) + nums[l];
                l = r;
            }
            nums = temp;
        }
        return nums;
    }
    bool isMatch(string s, string p)
    {
        int lenS = s.size(), lenP = p.size();
        vector<vector<int>> match(lenS + 1,vector<int>(lenP + 1));

        // initialize
        for (int j = 1; j < lenP + 1; j++)
        {
            if (p[j-1]=='*'){
                match[0][j]=true;
            }else{
                break;
            }
        }
        match[0][0]=true;
        // dp start
        for (int i = 1; i < lenS + 1; i++)
        {
            for (int j = 1; j < lenP + 1; j++)
            {
                if (s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    match[i][j] = match[i - 1][j - 1];
                }
                else if (p[j-1] == '*')
                {
                    match[i][j] = match[i][j - 1] | match[i - 1][j];
                }
            }
        }

        return match[lenS][lenP];
    }
};
int main()
{
    vector<int> a{1,2,3};
    Solution so;
    cout << so.countAndSay(4);
    return 0;
}