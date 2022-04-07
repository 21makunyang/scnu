#include "tools.h"
char* strcpy(char* s1,char *s2)
{
    int lenOfS2;
    if(s1!=nullptr){
        s1[0]='\0';
        delete[] s1;
        s1=nullptr;
    }
    if(s2==nullptr) return s1;
    for(lenOfS2=0;s2[lenOfS2+1]!='\0';lenOfS2++)
    s1 = new char[lenOfS2];
    for(int i=0;s1[i+1]!='\0';i++)
    {
        s1[i]=s2[i];
    }
    return s1;
}
