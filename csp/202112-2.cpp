#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, N, num;
    cin >> n >> N;
    vector<int> A(n + 2, {0});
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    A[n + 1] = N;
    int r = N / (n + 1), i = 0,len = 0;
    long long sum = 0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = A[i]; j < A[i+1]; j+=len)
        {
            len = r*(j/r+1)-j;
            if(len> A[i+1]-j) len = A[i+1]-j;
            sum+=len*abs(j/r-i);
        }
        
    }
    
    cout << sum << '\n';
    return 0;
}