#include <bits/stdc++.h>
using namespace std;

bool validR(string s)
{
    if (s.size() < 1)
    {
        return false;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '_' && !('A' <= s[i] && s[i] <= 'Z') && !('a' <= s[i] && s[i] <= 'z') && !('0' <= s[i] && s[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

bool validU(string s)
{
    if (s.size() > 16 || s.size() < 1)
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '_' && !('A' <= s[i] && s[i] <= 'Z') && !('a' <= s[i] && s[i] <= 'z') && !('0' <= s[i] && s[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str, rear;
    int sizeOfHostName = 0, pre = 0;
    bool hasAt = false;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '@')
        {
            hasAt = true;
            rear = str.substr(i + 1, str.size() - i - 1);

            if (!validU(str.substr(pre, i - pre)))
            {
                cout << "NO" << '\n';
                return 0;
            }

            break;
        }
    }

    if (!hasAt)
    {
        cout << "NO" << '\n';
        return 0;
    }

    int index = rear.find("/");
    // if(rear.size()<1){
    //  cout << "NO" << '\n';
    //  return 0;
    // }
    string hostname, resource;
    bool hasR = false;
    if (index >= rear.size())
    {
        hostname = rear;
        resource = "";
    }
    else
    {
        hasR = true;
        hostname = rear.substr(0, index);
        resource = rear.substr(index + 1, rear.size() - index - 1);
    }

    pre = 0;
    for (int i = 0; i < hostname.size(); i++)
    {
        // 123@aaa./123
        if (hostname[i] == '.')
        {
            if (i == 0 || i == hostname.size()-1 || !validU(hostname.substr(pre, i - pre)))
            {
                cout << "NO" << '\n';
                return 0;
            }
            pre = i + 1;
        }
        sizeOfHostName++;
    }
    if (!validU(hostname.substr(pre,hostname.size()-pre)))
    {
        cout << "NO" << '\n';
        return 0;
    }
    if (sizeOfHostName > 32 || sizeOfHostName < 1 || (hasR && !validR(resource)))
    {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    return 0;
}