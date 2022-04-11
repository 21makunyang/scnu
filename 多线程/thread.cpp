#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
//g++ thread.cpp -o thread -lpthread
#define NumOfThreads 3

void *print(void *threadId)
{
    int  tid = *((int*)threadId);
    cout<<"hello threadId "<<tid<<endl;
    pthread_exit(NULL);
    return 0;
}
int main()
{
    pthread_t threads[NumOfThreads];
    int inchexes[NumOfThreads];
    int rc,i;
    try
    {
        for(i=0;i<NumOfThreads;i++)
        {
            inchexes[i] = i;
            rc = pthread_create(&threads[i] , NULL , print , (void*)&(inchexes[i]));
            if(rc)
            {
                throw("Fail to create thread!");
            }
        }
    }
    catch(const char* msg){
        cerr<<msg<<'\n';
        exit(-1);
    }
    return 0;
}