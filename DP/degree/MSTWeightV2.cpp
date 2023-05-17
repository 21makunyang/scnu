// kruskal 用并查集，并且合并时直接路径压缩，不按秩合并 
#include<bits/stdc++.h>	//POJ不支持

#define rep(i,a,n) for (int i=a;i<=n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>=n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair

using namespace std;
int N, M;
int w;
vector<int> parents;
vector<int> toBeDel;
struct E
{
    int from;
    int to;
    int w;
    E(){};
    E(int f, int t, int we) : from(f), to(t), w(we) {}
    bool operator<(const E &obj) const
    {
        return this->w < obj.w;
    }
};
int getParent(int n)
{
    return n == parents[n] ? n : parents[n] = getParent(parents[n]);
}

bool isSameTree(int n, int m)
{
    return getParent(n) == getParent(m);
}

void unionTree(int n, int m)
{
    parents[getParent(n)] = getParent(m);
}
vector<E> edges;
bool hasAnotherSubTree()
{

    for (int i = 0; i < toBeDel.size(); i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            parents[j] = j;
        }

        int w2 = 0, edgeN = 0;
        for (int j = 0; j < M; j++)
        {
            if (toBeDel[i] == j)
                continue;
            if (!isSameTree(edges[j].from, edges[j].to))
            {
                unionTree(edges[j].from,edges[j].to);
                w2 += edges[j].w;
                edgeN++;
            }
        }
        if (edgeN == N-1 && w2 == w)
            return true;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    edges.resize(M);
    parents.resize(N + 1);
    for (int i = 1; i < N + 1; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < M; i++)
    {
        if (!isSameTree(edges[i].from, edges[i].to))
        {
            unionTree(edges[i].from, edges[i].to);
            w += edges[i].w;
            if (i > 0 && edges[i].w == edges[i - 1].w || i < M - 1 && edges[i].w == edges[i + 1].w)
            {
                toBeDel.push_back(i);
            }
        }
    }
    int cnt = 1;
    for (int i = 1; i < N + 1; i++)
    {
        if (!isSameTree(1, i))
            cnt++;
    }
    if (cnt != 1)
    {
        cout << "No MST\n"
             << cnt << '\n';
        return 0;
    }
    cout << w << '\n';
    if (!hasAnotherSubTree())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}