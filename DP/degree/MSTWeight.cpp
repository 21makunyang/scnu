#include <bits/stdc++.h>
using namespace std;
vector<bool> visit{0};
int N, M;
vector<vector<int>> weight;
int cnt = 0;
vector<int> road(0);
vector<pair<int, int>> firstMSTEdges;
#define MAX_WEIGHT INT_MAX

struct E
{
    int from;
    int to;
    int w;
    E(){};
    E(int f, int t, int we) : from(f), to(t), w(we) {}
    bool operator<(const E &obj) const
    {
        return this->w > obj.w;
    }
};

int Prim(int beginNode, int deln1, int deln2)
{
    visit[beginNode] = true;
    int w = 0;
    priority_queue<E> edges;
    function<void(int)> pushEdges = [&](int node)
    {
        for (int i = 1; i <= N; i++)
        {
            if (weight[node][i] != MAX_WEIGHT)
                edges.push(E(node, i, weight[node][i]));
        }
    };
    pushEdges(beginNode);

    while (!edges.empty())
    {
        E edge = edges.top();
        edges.pop();

        if (visit[edge.to] || (edge.from == deln1 && edge.to == deln2) || (edge.from == deln2 && edge.to == deln1))
            continue; // if the node has been in subTree, check another edge.
        firstMSTEdges.push_back(make_pair(edge.from, edge.to));
        visit[edge.to] = true;
        w += edge.w;
        pushEdges(edge.to);
    }
    int index = 0;
    for (int i = 2; i < N + 1; i++)
    {
        if (!visit[i])
        {
            index = i;
            break;
        }
    }
    cnt++;
    if (index != 0)
    {
        Prim(index, 0, 0);
    }
    return w;
}
class HashGenerator
{
public:
    std::size_t operator()(const pair<int, int> &obj) const
    {
        return hash<int>()(obj.first) + hash<int>()(obj.second);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int n1, n2, w;
    visit.resize(N + 1);
    weight.resize(N + 1);
    road.resize(N + 1);
    road[1] = 1;
    for (int i = 0; i < N + 1; i++)
    {
        weight[i].resize(N + 1);
        for (int j = 0; j < N + 1; j++)
        {
            weight[i][j] = MAX_WEIGHT; // MAX_WEIGHT means unreachable
        }
    }
    unordered_map<int, int> wTable;
    unordered_set<pair<int, int>, HashGenerator> eqEdges;
    for (int i = 0; i < M; i++)
    {
        cin >> n1 >> n2 >> w;
        wTable[w]++;

        weight[n1][n2] = w;
        weight[n2][n1] = w;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (wTable[weight[i][j]] >= 2)
            {
                eqEdges.insert(make_pair(i, j));
            }
        }
    }

    int allWeight1 = Prim(1, 0, 0);
    if (cnt != 1)
    {
        cout << "No MST\n";
        cout << cnt << '\n';
        return 0;
    }
    cout << allWeight1 << '\n';
    int allWeight2;
    bool allSigned = true;
    for (int i = 0; i < firstMSTEdges.size(); i++)
    {
        auto f1 = eqEdges.find(make_pair(firstMSTEdges[i].first, firstMSTEdges[i].second));
        auto f2 = eqEdges.find(make_pair(firstMSTEdges[i].second, firstMSTEdges[i].first));
        if (f1 == eqEdges.end() && f2 == eqEdges.end())
        {
            allSigned = false;
            break;
        }
    }

    bool diff = false;
    for (auto eqEdge : eqEdges)
    {
        for (int j = 0; j < N + 1; j++)
        {
            visit[j] = false;
        }
        cnt=0;
        allWeight2 = Prim(1, eqEdge.first, eqEdge.second);
        if (cnt==1&&allWeight1 == allWeight2)
        {
            diff = true;
            break;
        }
    }
    //&& allSigned 
    if (!diff )
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}