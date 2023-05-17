#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,score,k;
    int scoresNum[101] = {0};
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>score;
        scoresNum[score]++;
    }
    int sum =0;
    for (int i = 100; i >= 0 ; i--)
    {
        sum+=scoresNum[i];
        if(sum>=k){
            break;
        }
    }
    cout<<sum<<'\n';
    return 0;
}