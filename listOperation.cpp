#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LPNode;

typedef struct List
{
    LPNode head;
    LPNode rear;
    List(){
        head=nullptr;
        rear=nullptr;
    }
}*LPList,List;

LPList createList() //创建
{
    List *list = new List;
    return list;
}
LPList inputData(LPList list) //输入
{
    int num,data,i;
    cout<<"请输入数据个数："<<'\n';
    cin>>num;
    if(num<1)
    {
        cout<<"输入失败"<<'\n';
        return list;
    }
    cout<<"请输入数据:"<<'\n';
    if(list->head==nullptr)
    {
        cin>>data;
        LPNode newNode = new Node;
        newNode->data=data;
        newNode->next=nullptr;
        list->head=newNode;
        list->rear=newNode;
        i=1;
    }
    else i=0;
    for(;i<num;i++)
    {
        cin>>data;
        LPNode newNode = new Node;
        newNode->data=data;
        newNode->next=nullptr;
        list->rear->next=newNode;
        list->rear=newNode;
    }
    cout<<"输入成功!"<<'\n';
    return list;
}
LPList insertData(LPList list) //插入
{
    int data,index;
    cout<<"请输入插入的数据："<<'\n';
    cin>>data;
    cout<<"请输入插入位置(数组位置从0开始)："<<'\n';
    cin>>index;
    LPNode p=list->head;
    if(list->head==nullptr) //数组为空
    {
        LPNode newNode = new Node;
        newNode->data=data;
        newNode->next=nullptr;
        list->head=newNode;
        list->rear=newNode;
        cout<<"插入成功"<<'\n';
        return list;
    }
    if(index==0) //插入队首
    {
        LPNode newNode = new Node;
        newNode->data=data;
        newNode->next=list->head->next;
        list->head=newNode;
        cout<<"插入成功"<<'\n';
        return list;
    }
    LPNode t=nullptr;
    for(int i=0;i<index;i++)
    {
        if(p==nullptr) //插入位置比数组大，插在最后
        {
            LPNode newNode = new Node;
            newNode->data=data;
            newNode->next=nullptr;
            list->rear->next=newNode;
            list->rear=newNode;
            cout<<"插入成功"<<'\n';
            return list;
        }
        t=p;
        p=p->next;
    }
    LPNode newNode = new Node;
    newNode->data=data;
    newNode->next=p;
    t->next=newNode;
    cout<<"插入成功"<<'\n';
    return list;
}
int output(LPList list) //输出
{
    if(list->head==nullptr)
    {
        cout<<"数组为空"<<'\n';
        return 1;
    }
    LPNode p=list->head;
    cout<<"数组内容为：";
    while(p!=nullptr)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<'\n';
    return 1;
}
int Sum(LPList list) //求和
{
    if(list->head==nullptr)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int num,sum=0,i;
    cout<<"请输入求和数组元素个数："<<'\n';
    reset: cin>>num;
    sum=0;
    LPNode p=list->head;
    for(i=0;i<num;i++)
    {
        if(p==nullptr)
        {
            cout<<"请重新输入"<<'\n';
            goto reset;
        }
        sum+=p->data;
        p=p->next;
    }
    cout<<"求和结果为："<<sum<<'\n';
    return 1;
}
int search(LPList list) //查找
{
    if(list->head==nullptr)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int num,count=0,total=0;
    bool isfirst=true; //找到则为false
    LPNode p=list->head;
    LPNode rear=nullptr;
    LPNode tem=new Node;
    tem->next=nullptr;
    cout<<"请输入查找元素："<<'\n';
    cin>>num;
    while(p!=nullptr)
    {
        if(p->data==num)
        {
            if(isfirst)
            {
                isfirst=false;
                LPNode newNode=new Node;
                newNode->data=count;
                newNode->next=nullptr;
                tem->next=newNode;
                rear=newNode;
            }
            else
            {
                LPNode newNode=new Node;
                newNode->data=count;
                newNode->next=nullptr;
                rear->next=newNode;
                rear=newNode;
            }
            total++;
        }
        count++;
        p=p->next;
    }
    if(isfirst)
    {
        cout<<"数组中无该元素"<<'\n';
    }
    else if(total==1)
    {
        cout<<"数组中有"<<total<<"个该元素"<<'\n'<<"位于第"<<tem->data<<"位置"<<'\n';
    }
    else{
        cout<<"数组中有"<<total<<"个该元素"<<'\n'<<"分别位于";
        p=tem;
        while(p!=nullptr)
        {
            cout<<"第"<<p->data<<",";
            p=p->next;
        }
        cout<<"位置"<<'\n';
    }
    delete[] tem;
    return 1;
}
int outTheNum(LPList list) //输出指定元素
{
    if(list->head==nullptr)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int index;
    LPNode p=list->head;
    cout<<"请输入指定输出位置(数组位置从0开始)："<<'\n';
    cin>>index;
    for(int i=0;i<index;i++)
    {
        p=p->next;
    }
    cout<<"指定位置元素为："<<p->data<<'\n';
    return 1;
}
LPList erase(LPList list) //删除
{
    if(list->head==nullptr)
    {
        cout<<"数组为空"<<'\n';
        return list;
    }
    int index;
    LPNode p=list->head;
    LPNode t=nullptr;
    cout<<"请输入删除位置(数组位置从0开始)："<<'\n';
    cin>>index;
    if(index==0)
    {
        p=p->next;
        delete list->head;
        list->head=p;
        cout<<"删除完成"<<'\n';
        return list;
    }
    for(int i=0;i<index;i++)
    {
        if(p==nullptr)
        {
            cout<<"删除失败"<<'\n';
            break;
        }
        t=p;
        p=p->next;
    }
    p=p->next;
    delete t->next;
    t->next=p;
    cout<<"删除完成"<<'\n';
    return list;
}
int quickSort(LPNode head,LPNode rear)
{
    if(head==rear || head ==nullptr)
    {
        return 1;
    }
    LPNode p=head;
    LPNode q=head->next;
    while(q!=rear)
    {
        
        if(q->data<head->data){
            if(p==rear) break;
            swap(q->data,p->next->data);
            p=p->next;
        }
        q=q->next;
    }
    if(q->data<head->data){//到达队尾还需判断一次
        swap(q->data,p->next->data);
        p=p->next;
    }
    if(head->data > p->data) swap(head->data,p->data);
    quickSort(head,p);
    quickSort(p->next,rear);
    return 1;
}
int main()
{
    LPList list =new List;
    while(1)
    {
        cout<<'\n';
        char oper;
        cout<<"请选择操作："<<'\n';
        cout<<"1.数组输入"<<'\n';
        cout<<"2.数组排序"<<'\n';
        cout<<"3.元素插入"<<'\n';
        cout<<"4.元素查找"<<'\n';
        cout<<"5.元素删除"<<'\n';
        cout<<"6.数组输出"<<'\n';
        cout<<"7.输出指定位置元素"<<'\n';
        cout<<"8.对指定个数的数组元素求和"<<'\n';
        cout<<"9.退出"<<'\n';
        cin>>oper;
        if(oper<='0' || oper>'9')
        {
            cout<<"输入非指定命令，请重新输入"<<'\n';
            continue;
        }
        if(oper=='9')
        {
            delete [] list;
            cout<<"bye~"<<'\n';
            break;
        } 
        if(oper=='1') inputData(list);
        if(oper=='2') quickSort(list->head,list->rear);
        if(oper=='3') insertData(list);
        if(oper=='4') search(list);
        if(oper=='5') erase(list);
        if(oper=='6') output(list);
        if(oper=='7') outTheNum(list);
        if(oper=='8') Sum(list);
    }
    return 0;
}