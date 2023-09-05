#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (int i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;

#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    float a,b;
    cin>>a>>b;
    printf("Area=%.6f\n",a*b);
    printf("Perimeter=%.6f\n",2*(a+b));
    return 0;
}
// int main(){


// return 0;
// }