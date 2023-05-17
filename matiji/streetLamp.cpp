#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,k,b,index;
    cin>>n>>k>>b;
    vector<bool> brokenLamps(n,{0});

    for (int i = 0; i < b; i++)
    {
        cin>>index;
        brokenLamps[index-1]=true;
    }
    
    int l=0, r = 0;
	int cnt = 0;
	for( ;r < k;) {
		if( brokenLamps[r]) {
			cnt++;
		}
		r++;
	}
	int ans = cnt;
	for(; r < n;) {
		if (brokenLamps[r] ){
			cnt++;
		}
		if (brokenLamps[l]) {
			cnt--;
		}
		ans = min(ans, cnt);
		r++;
		l++;
	}
    cout<<ans<<'\n';
    return 0;
}