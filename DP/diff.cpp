#include <bits/stdc++.h>
using namespace std;
int longestSeq = 0;
string diff(string &A, string &B)
{
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, {0}));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    longestSeq = dp[n][m];
    if (dp[n][m] == 0)
    {
        return "No difference found";
    }
    vector<vector<int>> route(dp[n][m],vector<int>(2));
    function<void(int, int)> longest =
        [&](int lenA, int lenB)
    {
        int length = dp[n][m];
        while (length--)
        {
            while (dp[lenA-1][lenB]!=dp[lenA][lenB-1]||dp[lenA][lenB]!=dp[lenA-1][lenB-1]+1)
            {
                dp[lenA][lenB] == dp[lenA][lenB-1]?lenB--:lenA--;
            }
            route[length][0]=--lenA;
            route[length][1]=--lenB;
        }
        
    };
    longest(n, m);
    int line=1, AIndex = 0, BIndex = 0;
    cout<<"line #"<<line++<<'\n';
    int length =dp[n][m];
    string str;
    for (int i = 0; i < length; i++)
    {
        int beginA = AIndex;
        int beginB = BIndex;
        while(AIndex<route[i][0])AIndex++;
        while(BIndex<route[i][1])BIndex++;
        if(1==AIndex-beginA&&1!=BIndex-beginB){
            for (int j = beginB+1; j < BIndex; j++)
            {
                str += B[j];
            }
            str+="+";
        }else if (1!=AIndex - beginA&&1!=BIndex-beginB)
        {
            for (int j = beginA; j < AIndex; j++)
            {
                str+=A[j];
            }
            str+="-";
            for (int j = beginB; j < BIndex; j++)
            {
                str+=B[j];
            }
            str+="+";
            
        }else if (1!=AIndex-beginA&&1==BIndex-beginB)
        {
            for (int j = beginA; j < AIndex; j++)
            {
                str+=A[j];
            }
            str+="-";
        }
        
        if(A[AIndex]=='&'&&AIndex!=route[length-1][0]){
            str+="\nline #"+to_string(line++)+":\n";
        }
    }
    str+="\n";
    return str;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    string str;
    cin >> n >> m;
    cin.ignore(1);
    vector<string> ans;
    string A,B;
    for (int i = 0; i < n; i++)
    {
        getline(cin,str);
        A+=str+"\n";
    }

    for (int i = 0; i < m; i++)
    {
        getline(cin,str);
        B+=str+"\n";
    }
    int bigger = max(n,m),smaller = min(n,m);
    // for(int i=  0;i<smaller;i++){
    //     ans.push_back(diff(A[i],B[i]));
    // }
    ans.push_back(diff(A,B));
    cout<<ans[0]<<'\n';

    bool noDiff = true;
    for(auto a : ans){
        if(a != ""){
            noDiff = false;
            break;
        }
    }
    if(noDiff){
        cout<<"No difference found\n";
        return 0;
    }
    bool allDiff = true;
    cout<<longestSeq<<'\n';
    // for (int i = 0; i < smaller; i++)
    // {
    //     cout<<"Line #"<<i+1<<'\n';
    //     cout<<ans[i]<<'\n';
    // }
    
    return 0;
}

// 5 5

// This line is the same&
// This is a test&
// which is more comple&
// &
// than &

// This line is the same&
// This is a test&
// which is more complicated&
// zzz&
// than ...&

// This line is the same&
// This is another test&
// of the project&
// which is much more complex&
// than the previous one&
