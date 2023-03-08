#include <iostream>
using namespace std;

class Solution {
public:
    bool compare(char s, char t){
        if(s=='I' && (t=='V'||t=='X')) return true;
        if(s=='X' && (t=='L'||t=='C')) return true;
        if(s=='C' && (t=='D'||t=='M')) return true;
        return false;
    }
    int getNum(char s){
        if(s=='I') return 1;
        if(s=='V') return 5;
        if(s=='X') return 10;
        if(s=='L') return 50;
        if(s=='C') return 100;
        if(s=='D') return 500;
        if(s=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int j = 1, i = 0;
        int sum = 0;
        while(i<s.length()){
            if(j<s.length() && compare(s[i],s[j])){
                sum+=(getNum(s[j])-getNum(s[i]));
                j+=2;
                i+=2;
            }else{
                sum+=getNum(s[i]);
                i++;
                j++;
            }
        }
        return sum;
    }
};
int main(){
	Solution so;
	cout<<so.romanToInt("III");
    return 0;
}