#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> c, a;

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    a.resize(n + 1);
    c.resize(n + 1);
    c[0] = 1.0;

    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &a[i]);
        c[i] = c[i - 1] * a[i];
    }

    vector<int> pending(n + 1);
    pending[0]=0;
    for (int i = 1; i < n+1; i++)
    {
        pending[i] = (m%c[i]) - pending[i-1];
        printf("%d ",pending[i]/c[i-1]);
    }
    printf("\n");
    return 0;
}