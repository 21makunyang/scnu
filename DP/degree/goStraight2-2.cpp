#include <bits/stdc++.h>
using namespace std;
int N, K;
string beCity, endCity;
#define MAX_DIST INT_MAX
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> beCity >> endCity;
    vector<bool> visit(N, {0});
    vector<int> totalEnemy(N, {0});
    string cityName;
    vector<int> enemy(N);
    unordered_map<string, int> cityInfo;
    vector<string> cityN(N);
    string city1, city2;
    int length, c1, c2;
    vector<vector<int>> len(N, vector<int>(N));
    vector<int> dist(N);
    vector<int> liberate(N);
    vector<int> parent(N);
    vector<int> cnt(N,{0});
    // input city info

    cityInfo[beCity] = 0;
    totalEnemy[0] = 0;
    enemy[0] = 0;
    cityN[0] = beCity;
    for (int i = 1; i < N; i++)
    {
        cin >> cityName >> enemy[i];
        cityInfo[cityName] = i;
        cityN[i] = cityName;
        totalEnemy[i] = enemy[i];
    }

    // input road info
    // initialize
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            len[i][j] = MAX_DIST;
    for (int i = 0; i < N; i++)
        len[i][i] = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> city1 >> city2 >> length;
        c1 = cityInfo[city1];
        c2 = cityInfo[city2];
        len[c1][c2] = length;
        len[c2][c1] = length;
    }

    visit[0] = true;
    parent[0] = 0;
    int minDist = MAX_DIST;
    int dIndex = cityInfo[endCity];
    for (int i = 0; i < N; i++)
    {
        dist[i] = len[0][i];
        if (dist[i] != MAX_DIST)
        {
            liberate[i] = 1;
            cnt[i]=1;
        }
        else
        {
            liberate[i] = 0;
            cnt[i]=0;
        }
    }
    cnt[0]=0;
    liberate[0] = 0;

    
    // dijkstra
    for (int i = 0; i < N; i++)
    {
        int minIndex = 0, min = MAX_DIST;

        for (int j = 0; j < N; j++)
        {
            if (!visit[j] && min > dist[j])
            {
                minIndex = j;
                min = dist[j];
            }
        }
        visit[minIndex] = true;
        for (int j = 0; j < N; j++)
        {
            if (visit[j]||dist[minIndex] == MAX_DIST || len[minIndex][j] == MAX_DIST) continue;
            if (dist[j] > dist[minIndex] + len[minIndex][j]) // fastest path
            {
                dist[j] = dist[minIndex] + len[minIndex][j];
                liberate[j] = liberate[minIndex] + 1;
                totalEnemy[j] = totalEnemy[minIndex] + enemy[j];
                parent[j] = minIndex;
                cnt[j]=cnt[minIndex];
            }
            else if (dist[j] == dist[minIndex] + len[minIndex][j])
            {
                if (liberate[j] < liberate[minIndex] + 1)
                {
                    // if length of paths are the same, chose the path with the largest number of cities
                    liberate[j] = liberate[minIndex] + 1;
                    totalEnemy[j] = totalEnemy[minIndex] + enemy[j];
                    parent[j] = minIndex;
                    
                }
                else if ((liberate[j] == liberate[minIndex] + 1) && (totalEnemy[j] < totalEnemy[minIndex] + enemy[j]))
                {
                    // if length of paths and the numbers of citys of paths are the same, chose the path with the largest number of enemies
                    totalEnemy[j] = totalEnemy[minIndex] + enemy[j];
                    parent[j] = minIndex;
                    
                }
                cnt[j]+=cnt[minIndex];
            }
        }
    }
    int tem = dIndex;
    stack<string> stk;
    while (tem != 0)
    {
        stk.push(cityN[tem]);
        tem = parent[tem];
    }
    stk.push(beCity);
    cout << stk.top();
    stk.pop();
    while (!stk.empty())
    {
        cout << "->" << stk.top();
        stk.pop();
    }
    cout << '\n' << cnt[dIndex] << ' ' << dist[cityInfo[endCity]] << ' ' << totalEnemy[cityInfo[endCity]];
    return 0;
}