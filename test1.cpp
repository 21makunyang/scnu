#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const double pi = acos(-1);
int n;
int t;
int M[8][8];
int Q[8][8] = {0};
double MM[8][8];

void inputQ()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            cin >> Q[i][j];
        }
    }
}

void inputM(int n)
{
    int i = 0, j = 0;
    int k = 1;
    cin >> M[0][0];
    while (k <= n)
    {
        if (i == 0 && j < N) // 到顶了
        {
            j++;
            int ii = j;
            int jj = i;
            while (i != ii && j != jj && k < n)
            {
                cin >> M[i][j];
                k++;
                i++;
                j--;
            }
            if (k == n)
                return;
            cin >> M[i][j];
            k++;
        }
        if (j == 0 && i < N && k <= n) // 到左边
        {
            i++;
            int ii = j;
            int jj = i;
            while (i != ii && j != jj && k < n)
            {
                cin >> M[i][j];
                k++;
                i--;
                j++;
            }
            if (k == n)
                return;
            cin >> M[i][j];
            k++;
        }
        if (i == N)
        {
            j++;
            int ii = j;
            int jj = i;
            while (i != ii && j != jj && k < n)
            {
                cin >> M[i][j];
                k++;
                i--;
                j++;
            }
            if (k == n)
                return;
            cin >> M[i][j];
            k++;
        }
        if (j == N)
        {
            i++;
            int ii = j;
            int jj = i;
            while (i != ii && j != jj && k < n)
            {
                cin >> M[i][j];
                k++;
                i++;
                j--;
            }
            if (k == n)
                return;
            cin >> M[i][j];
            k++;
        }
    }
}

void lh()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            M[i][j] = M[i][j] * Q[i][j];
        }
    }
}

void ls()
{
    double au = 1, av = 1;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            double f = 0.0;
            for (int u = 0; u <= N; u++)
            {
                for (int v = 0; v <= N; v++)
                {
                    au = 1, av = 1;
                    if (u == 0)
                        au = sqrt(1.0 / 2);
                    if (v == 0)
                        av = sqrt(1.0 / 2);
                    f = f + au * av * M[u][v] * cos((pi / 8.0) * (i + 0.5) * u) * cos((pi / 8.0) * (j + 0.5) * v);
                }
            }
            MM[i][j] = f / 4.0;
        }
    }
}

void add()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            int t = int(MM[i][j] + 128 + 0.5);
            if (t > 255)
                t = 255;
            if (t < 0)
                t = 0;
            M[i][j] = t;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inputQ();
    cin >> n;
    cin >> t;
    inputM(n);
    cout << endl;
    if (t == 0)
    {
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                cout << M[i][j] << " ";
                if (j == N)
                    cout << "\n";
            }
        }
    }
    if (t == 1)
    {
        lh();
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                cout << M[i][j] << " ";
                if (j == N)
                    cout << "\n";
            }
        }
    }
    if (t == 2)
    {
        lh();
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                cout << M[i][j] << " ";
                if (j == N)
                    cout << "\n";
            }
        }
        cout<<endl;
        ls();
        //add();
        cout << "out___________________\n";
        cout << "\n";
        cout << "\n";
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                cout << MM[i][j] << " ";
                if (j == N)
                    cout << "\n";
            }
        }
    }
    return 0;
}

// 16 11 10 16 24 40 51 61
// 12 12 14 19 26 58 60 55
// 14 13 16 24 40 57 69 56
// 14 17 22 29 51 87 80 62
// 18 22 37 56 68 109 103 77
// 24 35 55 64 81 104 113 92
// 49 64 78 87 103 121 120 101
// 72 92 95 98 112 100 103 99
// 26
// 2
// -26 -3 0 -3 -2 -6 2 -4 1 -3 1 1 5 1 2 -1 1 -1 2 0 0 0 0 0 -1 -1