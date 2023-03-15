#include <bits/stdc++.h>
using namespace std;
class DisjSet{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjSet(int maxSize):parent(vector<int>(maxSize)),
                        rank(vector<int>(maxSize,0))
    {
        for (int i = 0; i < maxSize; i++)
        {
            parent[i]=i;
        }
    }
    int find(int x){
        return x==parent[x]?x:(parent[x]=find(parent[x]));
    }
    void toUnion(int x,int y){
        int p1=find(x),p2=find(y);
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }else{
            parent[p1]=p2;
            if (rank[p1]==rank[p2]) rank[p2]++;
        }

    }
    bool isSame(int x,int y){
        return find(x)==find(y);
    }
};