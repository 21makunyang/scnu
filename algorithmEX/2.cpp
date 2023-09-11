#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)

int main(){
    string str;
    cin>>str;
    vector<int> siz;
    int n = str.length();
    int i = 0,be= 0,ans=0;
    while(i<n&&str[i]==str[i+1])i++;
    siz.push_back(i-be+1);
    i++;
    for(;i<n;i++){
        be = i;
        while(i<n&&str[i]==str[i+1])i++;
        siz.push_back(i-be+1);  
    }
    rep(j,0,siz.size()){
        ans+=siz[j]*siz[j];
    }
    if(siz.size()==1){
        cout<<ans<<'\n';
        return 0;
    }
    int maxIdx =0;
    for(int i=0;i<siz.size();i++){
        if(siz[i]>siz[maxIdx]) maxIdx = i;
    }
    int mid = siz[maxIdx];
    if(maxIdx==0){
        int af = siz[maxIdx+1];
        ans = max(ans,ans-mid*mid+(mid+1)*(mid+1)-af*af+(af-1)*(af-1));
    }
    else if(maxIdx==siz.size()-1){
        int af = siz[maxIdx-1];
        ans = max(ans,ans-mid*mid+(mid+1)*(mid+1)-af*af+(af-1)*(af-1));
    }
    else{
        int af = siz[maxIdx-1];
        ans = max(ans,ans-mid*mid+(mid+1)*(mid+1)-af*af+(af-1)*(af-1));
        af = siz[maxIdx+1];
        ans = max(ans,ans-mid*mid+(mid+1)*(mid+1)-af*af+(af-1)*(af-1));
    }
    cout<<ans<<'\n';
    return 0;
}