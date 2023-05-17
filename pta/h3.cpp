#include <bits/stdc++.h>
using namespace std;

// #define read(a) {char c;while((c=getchar())>47) a=a*10+(c^48);}
inline void read(int &a){
	a=0; char c;
	while((c=getchar())<48);
	do a=a*10+(c^48);
	while((c=getchar())>47);
}

int main()
{
    int N1, N2;
    read(N1);
    // cout<<N1;
    // cin >> N1;
    int *nums1 = new int[N1];
    for (int i = 0; i < N1; i++)
    {
        // cin>>nums1[i];
        read(nums1[i]);
    }

    // cin >> N2;
    read(N2);
    int mid = (N1+N2+1)/2;
    int cnt = 0,ans=0,index1=0,cur,value;
    bool getMid = false;
    for (int i = 0; i < N2; i++)
    {
        // cin>>cur;
        read(cur);
        if(!getMid && cnt<=mid){
            while(index1<N1 && nums1[index1]<cur){
                value = nums1[index1];
                index1++;
                cnt++;
                if(!getMid && cnt == mid){
                    ans = value;
                }
            }
            value = cur;
            cnt++;
            if(!getMid && cnt == mid){
                    ans = value;
            }
        }
    }
    cout<<ans<<'\n';
    // delete[] nums1;
    return 0;
}