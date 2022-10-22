
#include <iostream>
#include <cmath>
using namespace std;

inline string sum(string num){
    int sum = 0;
    int i=0;
    for(;i<num.length();i++){
        sum+=num[i]-'0';
    }
    string newNum;
    newNum = to_string(sum);
    return newNum;
}
int main(){
    int num,t,i;
    string number;
    string tem;
    cin>>num>>t>>number;
    
    for(int i=0;i<t;i++)
    {
        number = sum(number);
        if(tem == number)
            break;
        tem = number;
    }
    cout<<number;
    return 0;
}
