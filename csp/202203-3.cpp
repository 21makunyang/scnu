#include <bits/stdc++.h>
using namespace std;

struct node
{
    int id;        // 节点编号
    int block;     // 节点所在的可用区
    int num;       // 该节点的任务数
    unordered_set<int> task; // 该节点运行的任务编号
    bool operator<(const node &obj) const
    {
        return this->num!=obj.num?this->num < obj.num:this->id < obj.id;
    }
};
unordered_map<int, node> nodes; 

// 节点亲和性
void fna(int na, vector<int> &temp)
{
    for (auto it = temp.begin(); it != temp.end();)
    {
        if (nodes[*it].block != na)
        {
            temp.erase(it);
        }
        else
            it++;
    }
    return;
}

// 任务亲和性
void fpa(int pa, vector<int> &temp)
{
    unordered_set<int> kyq; 
    for (auto it = nodes.begin(); it != nodes.end(); it++)
    {
        if (it->second.task.count(pa) == 1)
        {
            kyq.insert(it->second.block);
        }
    }
    
    for (auto it = temp.begin(); it != temp.end();)
    {
        if (kyq.count(nodes[*it].block) == 0)
        {
            temp.erase(it);
        }
        else
            it++;
    }
    return;
}

// 任务反亲和性
vector<int> fpaa(int paa, vector<int> temp)
{
    for (auto it = temp.begin(); it != temp.end();)
    {
        if (nodes[*it].task.count(paa) == 1)
        {
            temp.erase(it);
        }
        else
            it++;
    }
    return temp;
}

bool cmp(int x, int y)
{
    return nodes[x] < nodes[y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> allNodesId; // 全部节点编号
    for (int i = 1; i <= n; i++)
    {
        int area;
        cin >> area; 
        nodes.insert(pair<int, node>(i, node{i, area, 0, unordered_set<int>()}));
        allNodesId.push_back(i);
    }
    int g;
    cin >> g;
    int f, a, na, pa, paa, paar;

    for (int i = 0; i < g; i++)
    {
        cin >> f >> a >> na >> pa >> paa >> paar;
        for (int j = 0; j < f; j++)
        {
            vector<int> temp = allNodesId, temp2;
            if (na != 0)
                fna(na, temp);
            if (pa != 0)
                fpa(pa, temp);
            if (paa != 0)
                temp2 = fpaa(paa, temp);
            
            if ((temp2.empty() && paar == 1) || temp.empty())
            {
                cout << "0"<< " ";
                continue;
            }
            
            else if (temp2.empty() && paar == 0)
            {
                temp2 = temp;
            }
            sort(temp2.begin(), temp2.end(), cmp);
            
            nodes[temp2[0]].num++;
            nodes[temp2[0]].task.insert(a);
            cout << nodes[temp2[0]].id << " ";
        }
        cout << "\n";
    }
    return 0;
}