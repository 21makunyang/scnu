// 描述

// 从给定的无序、不重复的数组A中，取出2个数，使其相加和为M。

// 输出该数组内所有满足上述条件的解的个数。

// 输入
// 第一行两个数 N 和 M，N 为数组长度，M 为相加之和。

// 第二行为实际的数组元素。

// 输出
// 解的个数

#include <bits/stdc++.h>
using namespace std;
#include <vector>

string longestPalindrome(string s)
{
    int n = s.length(), cur = 0, left, right;
    string curLongestStr, ans,tem="";
    curLongestStr=ans=s[0];
    for (cur = 0; cur < n - 1; cur++)
    {
        left = cur;
        right = cur;
        curLongestStr = s[cur];

        // bb
        if ((cur < n - 1) && (s[cur] == s[cur + 1]))
        {
            curLongestStr = s[cur] ;
            curLongestStr+= s[cur];
            right = cur + 1;
            while ((left > 0) && (right < n - 1) && (s[left - 1] == s[right + 1]))
            {
                left--;
                right++;
                tem=curLongestStr;
                curLongestStr = s[left];
                curLongestStr += tem;
                curLongestStr += s[right];
            }
            if (ans.length() < curLongestStr.length())
            {
                ans = curLongestStr;
            }
        }
        left = cur;
        right = cur;
        // bab
        if ((cur > 0) && (cur < n - 1) && (s[cur - 1] == s[cur + 1]))
        {
            curLongestStr =s[--left] ;
            curLongestStr+= s[cur];
            curLongestStr += s[++right];
            while ((left > 0) && (right < n - 1) && (s[left - 1] == s[right + 1]))
            {
                left--;
                right++;
                tem=curLongestStr;
                curLongestStr = s[left] ;
                curLongestStr+= tem;
                curLongestStr += s[right];
            }
        }
        if (ans.length() < curLongestStr.length())
        {
            ans = curLongestStr;
        }
    }
    return ans;
}
int main()
{
    // int N,M,i,j,count=0;
    // cin>>N>>M;
    // int nums[N];

    cout<<longestPalindrome("a");
    return 0;
}