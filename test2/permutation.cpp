#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,r,t,k;
vector<int> combination;
vector<vector<int>> ans;
void permutation(int index,int length){
    if (t==k){
        return;
    }
    if (length == r){
        k++;
        ans.push_back(combination);
        return;
    }
    for(int i = index;i>=1;i--){
        combination[length]= i;
        permutation(i-1,length+1);
    }
}
bool cmp(vector<int> x,vector<int> y){
    if (x[0]>y[0]){
        return true;
    }
    else if (x[0]<y[0]){
        return false;
    }else if(x[1]>y[1]){
        return true;
    }else if(x[1]<y[1]){
        return false;
    }else if (x[2]>y[2]){
        return true;
    }
    return false;
}
int main(){
    cin>>n>>r>>t;
    k=0;
    combination.resize(r,0);
    permutation(n,0);
    // sort(ans.begin(),ans.end(),cmp);
    for(int j = 0;j<t;j++){
        for (int i = 0; i < r; i++)
        {
            cout<<" "<<ans[j][i];
        }
        cout<<'\n';
    }
    return 0;
}