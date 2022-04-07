#include "Goods.h"

float getPrice(LPGoods goods)
{
    goods->price=goods->PreSalePeriod*goods->wholesalePrice;
    return goods->price;
}
LPGoods getData(LPGoods goods) //传入商品，输入信息，返回商品
{
    LPGoods childGoods=new Goods;
    if(goods->next==nullptr)
    goods->next=childGoods;
    childGoods->next=nullptr;
    cout<<"请输入商品编号：\n";
    cin>>childGoods->id;
    cout<<"请输入商品名称：\n";
    cin>>childGoods->name;
    cout<<"请输入商品批发价：\n";
    cin>>childGoods->wholesalePrice;
    cout<<"请输入商品预售天数：\n";
    cin>>childGoods->PreSalePeriod;
    childGoods->price=getPrice(childGoods);
    return goods;
}

void output(LPGoods goods)
{
    cout<<goods->name<<"的批发价为：";
    cout<<goods->wholesalePrice<<'\n';
    cout<<goods->name<<"的预售天数为：";
    cout<<goods->wholesalePrice<<'\n';
    cout<<goods->name<<"的零售价为：";
    cout<<goods->wholesalePrice<<'\n';
    return;
}
