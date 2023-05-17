#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,num;
    scanf("%d%d",&n,&m);
    vector<int> p(m),t(m),earliest(m),latest(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&num);
        p[i] = num-1;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&t[i]);
    }
    bool canBeDone = true;
    for (int i = 0; i < m; i++)
    {
        if(p[i]!=-1){
            earliest[i] = earliest[p[i]]+t[p[i]];
        }else{
            earliest[i]=1;
        }
        printf("%d ",earliest[i]);
        if(earliest[i]+t[i]-1>n){
            canBeDone =false;
        }
    }
    printf("\n");
    if(!canBeDone){
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        latest[i] = n;
    }
    
    for (int i = m-1; i >= 0; i--)
    {
        latest[i] = latest[i]-t[i]+1;
        if(p[i]!=-1){
            if(latest[p[i]]>latest[i]-1) latest[p[i]] = latest[i]-1;
        }
        
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ",latest[i]);
    }
    printf("\n");
    return 0;
}