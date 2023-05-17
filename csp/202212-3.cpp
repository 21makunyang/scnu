#include <bits/stdc++.h>
using namespace std;
int Q[8][8], M[8][8] = {0};
int cosM[8][8];
void readData(int n)
{
    bool desc = true;
    int i = 0, j = 0;
    int cnt = 0;
    while (i != 7 || j != 0)
    {
        if (cnt >= n)
        {
            return;
        }
        if (i < 0)
        {
            i++;
            // desc = desc ? false : true;
            desc = false;
        }
        else if (j < 0)
        {
            j++;
            desc = true;
        }
        scanf("%d", &M[i][j]);
        cnt++;
        if (!desc)
        {
            i++;
            j--;
        }
        else
        {
            j++;
            i--;
        }
    }
    if (cnt >= n)
    {
        return;
    }
    scanf("%d", &M[7][0]);
    j++;
    desc = true;
    while (i != 7 || j != 6)
    {
        if (cnt >= n)
        {
            return;
        }
        if (i > 7)
        {
            i--;
            j += 2;
            // desc = desc ? false : true;
            desc = true;
        }
        else if (j > 7)
        {
            j--;
            i += 2;
            desc = false;
        }
        scanf("%d", &M[i][j]);
        cnt++;
        if (!desc)
        {
            i++;
            j--;
        }
        else
        {
            j++;
            i--;
        }
    }
    if (cnt >= n)
    {
        return;
    }
    scanf("%d", &M[7][6]);
    cnt++;
    if (cnt >= n)
    {
        return;
    }
    scanf("%d", &M[7][7]);
}
inline double a(int u)
{
    if (u == 0)
        return sqrt(0.5);
    return 1.0;
}
#define MY_PI acos(-1)
int main()
{
    // 1.读入量化矩阵Q
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%d", &Q[i][j]);
        }
    }
    int n, T;

    scanf("%d", &n);
    scanf("%d", &T);
    // 读入扫描数据
    readData(n);
    if (T == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            M[i][j] = M[i][j] * Q[i][j];
        }
    }
    if (T == 1)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
    else if (T == 2)
    {
        double sum = 0;
        int tem;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                sum = 0;
                for (int u = 0; u < 8; u++)
                {
                    for (int v = 0; v < 8; v++)
                    {
                        sum += a(u) * a(v) * double(M[u][v]) * cos(acos(-1) / 8.0 * (i + 0.5) * double(u)) * cos(acos(-1) / 8.0 * (j + 0.5) * double(v));
                    }
                }
                tem = round(0.25 * sum + double(128));
                if (tem < 0)
                {
                    cosM[i][j] = 0;
                }
                else if (tem > 255)
                {
                    cosM[i][j] = 255;
                }
                else
                {
                    cosM[i][j] = tem;
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", cosM[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}