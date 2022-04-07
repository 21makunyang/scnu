#include <bits/stdc++.h>
int main()
{
    int a,b,c,d;
    FILE *p=fopen("test.txt","r");
    if(p==nullptr)
    {
        p=fopen("test.txt","w+");
        fprintf(p,"1 2");
        fclose(p);
        p=fopen("test.txt","r");
    }
    fscanf(p,"%d %d",&a,&b);
    rewind(p);
    fscanf(p,"%d %d",&c,&d);
    fclose(p);
    a+=c;
    b+=d;
    p=fopen("test.txt","w");
    fprintf(p,"%d %d",a,b);
    fclose(p);
    return 0;
}