#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Goods
{
    int id; //商品编号 id>0
    char name[20]; //商品名
    float wholesalePrice; //批发价
    int PreSalePeriod; //预售天数 >0
    float price; //零售价 >0
    struct Goods *next;//下个商品
}Goods,*LPGoods;

LPGoods getData(LPGoods);//传入商品，输入信息，返回商品
float getPrice(LPGoods); //传入商品，计算零售价为预售天数乘批发价，返回商品零售价
void output(LPGoods); //传入商品，输出信息
