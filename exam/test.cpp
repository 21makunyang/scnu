#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    /*判断每个字符属于0-9还是a-z*/
	char getChar(int n){
		if(n <= 9) return n+'0';
		else return n-10+'a';
	}
	
	int getInt(char ch){
		if('0' <= ch && ch <= '9') return ch - '0';
		else return ch - 'a' + 10;
	}
	
	string add36Strings(string num1, string num2){
		int carry = 0;
		int i = num1.size()-1, j = num2.size()-1;
		string res;
		while(i>=0 || j>=0 || carry){
            // 这里使用三目运算符，可以减少运行时间
			int x = i >= 0 ? getInt(num1[i]) : 0;
			int y = j >= 0 ? getInt(num2[j]) : 0;
			int sum = x + y + carry;
			res += getChar(sum%36);
			carry = sum/36;
			i--,j--;
		}
		reverse(res.begin(),res.end());
		return res;  
	}
};
 
int main ()
{
	Solution s;
	string a = "b", b = "x", c;
	c = s.add36Strings(a,b);
	cout << c << endl;
}