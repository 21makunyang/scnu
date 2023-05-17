#include<bits/stdc++.h>
using namespace std;

int mod=0;
int numList[2001]={0};
void func_arg(char ch, int &h)
{
	if(ch>='A'&&ch<='Z')
	{
		if(mod==0)numList[h++]=ch-'A';
		else if(mod==1)
		{
			numList[h++]=28;
			numList[h++]=28;
			numList[h++]=ch-'A';
			mod=0;
		}
		else if(mod==-1)
		{
			numList[h++]=28;
			numList[h++]=ch-'A';
			mod=0;
		}
	}
	else if(ch>='a'&&ch<='z')
	{
		if(mod==1)numList[h++]=ch-'a';
		else 
		{
			numList[h++]=27;
			numList[h++]=ch-'a';
			mod=1;
		}
	}
	else if(ch>='0'&&ch<='9')
	{
		if(mod==-1)numList[h++]=ch-'0';
		else 
		{
			numList[h++]=28;
			numList[h++]=ch-'0';
			mod=-1;
		}
	}
} 
int main()
{
	int w=0, s=0;
	scanf("%d%d", &w, &s);
	char ch;
	scanf("%c", &ch);
	int h=1;
	scanf("%c", &ch);
	while(ch!='\n')
	{
		func_arg(ch, h);
		scanf("%c", &ch);
	}
	if(h%2==0)numList[h]=29;
	else h--;
	int n=0, supply=0;	
	if(s==-1)n=1+(h/2);
	else n=1+(h/2)+pow(2, s+1);
	for(int i=1; ;i++)
	{
		if(w*i>=n)
		{
			supply=w*i-n;
			n=1+(h/2)+supply;
			break;
		}
	}
	int d[2001]={0};
	d[0]=n;
	for(int i=1; i<=(h/2); i++)
	{
		d[i]=numList[2*i-1]*30+numList[2*i];
	}
	int end=h/2+supply;
	for(int i=h/2+1; i<=end; i++)
	{
		d[i]=900;
	}
	for(int i=0; i<=end; i++)
	{
		printf("%d\n", d[i]);
	}
  
	int k=0;
	if(s!=-1)k=pow(2, s+1);
	int g[550]={0};
	g[0]=1;
	int a=-3;
	for(int i=1; i<=k; i++)
	{
		for(int j=i; j>0; j--)
		{
			g[j]=(g[j]+(g[j-1]*a))%929;
		}
		a=(a*3)%929;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<=i+k; j++)
		{
			d[j]=d[j]-(d[i]*g[j-i])%929;
		}
	}
	for(int i=n; i<n+k; i++)
	{
		printf("%d\n", ((-d[i])%929+929)%929);
	}
	return 0;
}