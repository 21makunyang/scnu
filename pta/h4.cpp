#include <bits/stdc++.h>
using namespace std;

struct Edge{
    Edge* next;
    int point;
    Edge():next(nullptr),point(-1){}
    Edge(int p,Edge* n):next(n),point(p){}
};
string judge(vector<Edge> &edges,map<int, bool> &distroy,int n){
    bool hasDistroyed = false;
    Edge* temp;
    for (int i = 0; i < n; i++)
    {
        hasDistroyed = distroy.find(i)!=distroy.end();
        if(hasDistroyed){
            continue;
        }
        temp = edges[i].next;
        while(temp!=nullptr){
            hasDistroyed = distroy.find(temp->point)!=distroy.end();
            if(!hasDistroyed){
                return "NO";
            }
            temp = temp->next;
        }
    }
    return "YES";
}
int main()
{
    int n, m, begin, end,K,num;
    cin >> n >> m;
    vector<Edge> edges(n);
    Edge* temp;
    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        end--;
        begin--;
        temp=edges[begin].next;
        edges[begin].next = new Edge(end,temp);
        temp = edges[end].next;
        edges[end].next = new Edge(begin,temp);
    }
    cin>>K;
    int city;
    map<int,bool> distroy;
    for (int i = 0; i < K; i++)
    {
        cin>>num;
        distroy.clear();
        for(int j = 0;j<num;j++){
            cin>>city;
            distroy[city-1] = true;
        }
        cout<<judge(edges,distroy,n)<<'\n';
    }
    
    
    return 0;
}