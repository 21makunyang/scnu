#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, num, k = 0, ans, nex;
    cin>>n;
    string oper;
    // char oper;
    map<int, int> dic;
    map<int, int>::iterator iter;
    for (int i = 0; i < n; i++)
    {
        // cin.ignore('\n');
        // oper= cin.get();
        cin >> oper;
        // if(oper=='\n'){
        //     oper= cin.get();
        // }
        if (oper[0] == '+')
        {
            cin >> num;
            
            dic[num]++;
            k++;
        }
        else
        {
            int t = 0, tOfElem;
            bool flag = k % 2 == 0;
            bool get=false;
            for (iter = dic.begin(); iter != dic.end(); iter++)
            {
                
                tOfElem = 0;
                while (t != k / 2 - 1 && tOfElem != iter->second)
                {
                    tOfElem++;
                    t++;
                }

                if (flag && t == k / 2 - 1)
                {
                    ans = iter->first;
                    tOfElem++;
                    if (tOfElem < iter->second)
                    {
                        nex = iter->first;
                    }
                    else
                    {
                        iter++;
                        nex = iter->first;
                    }
                    printf("%.1f\n", (float(ans) + float(nex))/2.0);
                    get=true;
                    // goto next;
                }
                else if (t == k / 2 - 1)
                {
                    tOfElem++;
                    if (tOfElem < iter->second)
                    {
                        ans = iter->first;
                    }
                    else
                    {
                        iter++;
                        ans = iter->first;
                    }
                    cout << ans << '\n';
                    get=true;

                    // goto next;
                }

                if(get){
                    break;
                }
            }
        }
    // next:
    }
    return 0;
}