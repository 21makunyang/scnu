
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
//https://leetcode.cn/problems/course-schedule-iii/?envType=daily-question&envId=2023-09-11
inline int read(){
    int data=0,w=1;char ch=0;
    while(ch!='-' && (ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0' && ch<='9')data=data*10+ch-'0',ch=getchar();
    return data*w;
}


bool cmp(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> q;
        sort(courses.begin(),courses.end(),cmp);

        
    }
};
int main(){


    return 0;
}