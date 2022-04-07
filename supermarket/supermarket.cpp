#include "Goods.h"

int main()
{
    LPGoods goods=nullptr;
    goods->next=nullptr;
    getData(goods);
    getPrice(goods);
    output(goods);
    return 0;
}