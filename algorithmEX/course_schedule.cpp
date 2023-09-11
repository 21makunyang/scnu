#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (int i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
//https://leetcode.cn/problems/course-schedule/?envType=daily-question&envId=2023-09-09
inline int read(){
    int data=0,w=1;char ch=0;
    while(ch!='-' && (ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0' && ch<='9')data=data*10+ch-'0',ch=getchar();
    return data*w;
}
class cmp{
public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second; 
    }
};

#define MAX_V -1
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
        vector<int> in(numCourses,{0});
        vector<vector<int>> table(numCourses);
        for(auto & prerequisite:prerequisites){
            in[prerequisite[1]]++;
            table[prerequisite[0]].push_back(prerequisite[1]);
        }
        rep(i,0,numCourses+1)
        {
            int zeroIdx = 0;
            rep(j,0,numCourses){
                if(in[j]==0) {
                    zeroIdx = j;
                    break;
                }
            } 
            if(in[zeroIdx]==MAX_V) break;
            for(auto& next:table[zeroIdx]){
                in[next]--;
            }
            in[zeroIdx] = MAX_V;
        }
        for(auto  elem:in){
            if(elem!=MAX_V){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Solution so;
    int numCourses =2;

    vector<vector<int>> prerequisites{{1,0},{0,1}};
    cout<<so.canFinish(numCourses,prerequisites);
    return 0;
}