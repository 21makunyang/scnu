#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &nums,int left,int right,int k){
    for(int i = left;i<right;i++){
        if(k == 0){
            return nums[i];
        }
        k--;
    }
    return -1;
}
int partition(vector<int> &nums,int left,int right,int k){
    int pivot = nums[left];
    int i=left,j =left+1;
    while(j<right){
        if(pivot<=nums[j]) j++;
        else {
            swap(nums[i+1],nums[j]);
            i++;
            if(i==right-1){
                break;
            }
        }
    }
    swap(nums[i],nums[left]);
    if(i - left< k-1){
        return partition(nums,i+1,right,k-i+left-1);
    }else if(i-left==k-1){
        return nums[i];
    }else{
        return partition(nums,left,i,k);
    }
    
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    cout<<partition(nums,0,n,k);
    return 0;
}