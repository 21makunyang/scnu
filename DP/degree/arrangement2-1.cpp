#include <bits/stdc++.h>
using namespace std;
int N, M, S, D;
struct Road
{
    int beCity, toCity;
    int len;
    int fee;
    Road *next;
    Road() : beCity(-1), toCity(-1), len(-1), fee(-1) {}
    Road(int c1, int c2, int l, int f) : beCity(c1), toCity(c2), len(l), fee(f) {}
    bool operator<(const Road &obj) const
    {
        return this->len < obj.len;
    }
};
#define MAX_DIST 250001
#define MAX_COST INT_MAX
struct City
{
    Road *nearCity;
    int dist;
    int length;
    int cost;
    void add(int beCity, int toCity, int len, int fee)
    {
        Road *tem = nearCity;
        nearCity = new Road(beCity, toCity, len, fee);
        nearCity->next = tem;
        return;
    }
    City() : nearCity(nullptr), dist(MAX_DIST), length(MAX_DIST), cost(MAX_COST) {}
    ~City()
    {
        Road *tem = nearCity;
        while (nearCity != nullptr)
        {
            tem = nearCity->next;
            delete nearCity;
            nearCity = tem;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> S >> D;
    vector<City> citys(N);
    int city1, city2, len, fee;
    Road cur;
    vector<Road> roads(2 * M);
    for (int i = 0; i < M; i++)
    {
        cin >> city1 >> city2 >> len >> fee;
        roads[i] = Road(city1, city2, len, fee);
        roads[i + M] = Road(city2, city1, len, fee);
    }
    citys[S].dist = 0;
    citys[S].length = 0;
    citys[S].cost = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * M; j++)
        {
            cur = roads[j];
            if (citys[cur.toCity].dist == citys[cur.beCity].dist + cur.len)
            {
                // len(S,u)==len(S,v)+len(v,w),更新最小花费
                citys[cur.toCity].cost = min(citys[cur.toCity].cost, citys[cur.beCity].cost + cur.fee);
            }
            else if (citys[cur.toCity].dist > citys[cur.beCity].dist + cur.len)
            {
                // len(S,u)>len(S,v)+len(v,w)，最小花费更新为cost(S,v)+cost(v,w)
                citys[cur.toCity].dist = citys[cur.beCity].dist + cur.len;
                citys[cur.toCity].cost = citys[cur.beCity].cost + cur.fee;
            }
        }
    }

    cout << citys[D].dist << ' ' << citys[D].cost << '\n';
    return 0;
}