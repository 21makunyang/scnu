// https://leetcode.cn/problems/making-file-names-unique/

// Given an array of strings names of size n.
// You will create n folders in your file system such that, at the ith minute, you will create a folder with the name names[i].

// Since two files cannot have the same name, if you enter a folder name that was previously used,
// the system will have a suffix addition to its name in the form of (k), where,
// k is the smallest positive integer such that the obtained name remains unique.

// Return an array of strings of length n where ans[i] is the actual name the system will assign to the ith folder when you create it.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        map<string, int> dir;
        vector<string> ans;
        string newName;
        int num;
        for (string key : names)
        {

            // key has been exist
            if (dir.find(key) != dir.end())
            {
                newName = key + "(" + to_string(dir[key]) + ")";
                num=1;
                while(dir.find(newName) != dir.end()){
                    newName=key + "(" + to_string(dir[key]+num) + ")";
                    num++;
                }
                dir[newName] = 1;
                dir[key]++;
            }
            else
            {
                newName = key;
                dir[key] = 1;
            }
            ans.push_back(newName);
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}