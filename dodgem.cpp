#include<bits/stdc++.h> 

using namespace std;

typedef pair<int,int> Car;

int main( )
{
    int n,t,pos,dire;
    cin>>n>>t;
    map<int,vector<int> >axis;
    // vector<Car> cars(n);
    for (int i = 0; i < n; i++)
    {
        cin>>pos>>dire;
        axis[pos].push_back(dire);
        // cars[i]=make_pair(pos,dire);
    }
    //simulation
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
        
    }
    
    return 0;
}