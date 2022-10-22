#define CURL_STATICLIB
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <fcntl.h>
#include <fcntl.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

//      http://bbs.pinggu.org/thread-1434803-1-1.html
#pragma comment(lib, "ws2_32.lib")
using namespace std;

string g_sHost;
string g_sObject;
int g_socket;
bool AnalyseURL(string url)
{
    if (string::npos == url.find("http://"))
        return false;
    if (url.length() <= 7)
        return false;

    int pos = url.find('/', 7);
    if (pos == string::npos)
    {
        g_sHost = url.substr(7);
        g_sObject = "/";
    }
    else
    {
        g_sHost = url.substr(7, pos - 7);
        g_sObject = url.substr(pos);
    }

    if (g_sHost.empty() || g_sObject.empty())
    {
        return false;
    }
    return true;
}

bool Connect()
{
    // initialize
    // WSADATA wd;
    // if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
    //     return false;

    // create socket
    g_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (g_socket == -1)
        return false;

    //解析域名为IP地址
    hostent *p = gethostbyname(g_sHost.c_str());
    if (p == nullptr)
        return false;

    // connect to web server
    sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(80);
    
    memcpy(&sa.sin_addr, *p->h_addr_list, 4);
    if (connect(g_socket, (sockaddr *)&sa, sizeof(sockaddr)))
        return false;
    return true;
}

string GetHtml(string url)
{
    if(false==AnalyseURL(url))
        return "";
    
    if(false==Connect())
        return "";

    string info;
    info+="GET "+g_sObject+" HTTP/1.1\n";
    info+="Host: "+g_sHost+"\n";
    info +="Connection: Close\n\n";
    send(g_socket,info.c_str(),info.length(),0);
    
    char ch;
    string html;
    while (recv(g_socket,&ch,sizeof(char),0))
    {
        html+=ch;
    }
    
    return html;
}
//  广州天气预报 http://www.tqyb.com.cn/index.html

int main()
{
    // get url
    string url;
    cout << "Enter url:\n";
    cin >> url;
    string content;
    content=GetHtml(url);
    ofstream input("data.txt",ios::out);

    input<<content<<'\n';
    input.close();
    return 0;
}