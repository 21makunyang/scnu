#include "bank.h"

int main()
{
    CAcount users("\0",1,0.1);
    // CAcount users1("mky",1,1000000000.0);
    // CAcount users2(users1);
    // users2.showData();
    output(users);
    //reset(users[2],users[1]);
    //output(users[2]);
    return 0;
}