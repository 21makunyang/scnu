// https://leetcode.cn/problems/decode-ways/

// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The test cases are generated so that the answer fits in a 32-bit integer.

// 先划分各种情况， 然后找条件， 
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
        {
            return 0;
        }
        //确定ans记录什么
        vector<int> ans(s.size() + 1);
        //初始化
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i <= s.size(); i++) //确定边界 s[i]能与s[i-1]结合也可独立 | s[i]只能独立 | s[i]只能跟s[i-1]结合 (需要考虑s[i]=='0'的特殊情况)
        {
            if ((s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') && s[i-1]!='0') //s[i-1]s[i]: 11~19 21~26
            {
                ans[i] = ans[i - 1] + ans[i - 2];
            }
            else if (s[i - 1] != '0') //s[i-1]s[i]: !(11~19 21~26) && s[i]!='0'
            {
                ans[i] = ans[i - 1];
            }
            else if (s[i - 2] == '1' || s[i - 2] == '2') //s[i-1]s[i]: 10、20
            {
                ans[i] = ans[i - 2];
            }
            else        //other
            {
                ans[i] = 0;
            }
        }
        return ans[(s.size())];
    }
};
int main()
{
    Solution so;
    cout << so.numDecodings("0123");
    return 0;
}