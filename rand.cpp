#include<iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n,seed,a,b,i,result;
	cin>>n>>seed>>a>>b;
	srand(seed);
	for(i=0;i<n;i++) result= rand() % (b-a+1) +a ;
	cout<<result;
	return 0;
}