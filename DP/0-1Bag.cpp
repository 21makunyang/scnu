#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, c, begin, end, t;
    cin >> n >> c;
    vector<int> w(n), p(n);
    vector<vector<int>> maxBag(n + 1, vector<int>(c + 1, {0}));
    vector<vector<string>> maxBagTrace(n + 1, vector<string>(c + 1));
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    // for(int i=0;i<n;i++){
    //     for(int j = c;j>=w[i];j--){
    //         if(maxBag[j]>maxBag[j-w[i]]+p[i]){
    //             maxBagTrace[j] = maxBagTrace[j]+"0";
    //             maxBag[j] = maxBag[j];
    //         }else{
    //             maxBagTrace[j] = maxBagTrace[j-w[i]]+"1";
    //             maxBag[j] =maxBag[j-w[i]]+p[i];
    //         }
    //     }
    //     for(int j = w[i]-1;j>=0;j--){
    //         maxBagTrace[j] = maxBagTrace[j]+"0";
    //     }
    // }
    int tem;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = c; j >= 0; j--)
        {
            if (j >= w[i - 1])
            {
                if (maxBag[i - 1][j - w[i - 1]] + p[i - 1] >= maxBag[i - 1][j])
                {
                    tem = maxBag[i][j];
                    maxBag[i][j] = maxBag[i - 1][j - w[i - 1]] + p[i - 1];
                    maxBagTrace[i][j] = maxBagTrace[i - 1][j - w[i - 1]] + "1";
                }
                else
                {
                    tem = maxBag[i][j];
                    maxBag[i][j] = maxBag[i - 1][j];
                    maxBagTrace[i][j] = maxBagTrace[i - 1][j] + "0";
                }
            }
            else
            {
                maxBag[i][j] = maxBag[i - 1][j];
                maxBagTrace[i][j] = maxBagTrace[i - 1][j] + "0";
            }
        }
    }
    cout << maxBag[n][c] << ' ';

    for (int j = 0; j < n + 1; j++)
    {
        if (maxBag[j][c] == maxBag[n][c])
        {
            cout << maxBagTrace[j][c];
            for (int i = maxBagTrace[j][c].size(); i < n; i++)
            {
                cout << "0";
            }
            break;
        }
    }

    return 0;
}