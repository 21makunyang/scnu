#define CURL_STATICLIB 
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
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
using namespace std;

int main()
{
    //create socket
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1) return 1;

    //get url
    string url;
    cin>>url;

    sockaddr_in my_sock;
    // bzero(&my_sock,sizeof(my_sock))
    my_sock.sin_family = AF_INET;
    my_sock.sin_port= htons(80);
    // my_sock.sin_addr.s_addr=inet_addr()
    hostent *p=gethostbyname("");

    return 0;
}
