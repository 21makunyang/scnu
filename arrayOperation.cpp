#include <bits/stdc++.h>
using namespace std;
int* arr;
int len;
/*
  输入数据合理性
  不使用new
  用户界面
  文件
  函数注释
  衔接
  需求
*/
int inputData()
{
    int num,data,i;
    cout<<"请输入数据个数："<<'\n';
    cin>>num;
    if(num<1)
    {
        cout<<"输入失败"<<'\n';
        return 0;
    }
    arr=new int[num];
    cout<<"请输入数据:"<<'\n';
    len=num;
    for(i=0;i<num;i++)
    {
       cin>>arr[i];
    }
    cout<<"输入成功!"<<'\n';
    return num;
}
int output() //输出
{
    if(len==0)
    {
        cout<<"数组为空"<<'\n';
        return 1;
    }
    cout<<"数组内容为：";
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return 1;
}
int quickSort(int a[],int left,int right)
{
    if(left<right)
    {
        int i=left+1,j=right;
        int pivot=a[left];
        while(i<j)
        {
            while(a[i]<pivot) i++;
            while(a[j]>pivot) j--;
            if(a[i]==a[j])break;
            else if(i<j) swap(a[i],a[j]);
        }
        if(a[left]>a[j]) swap(a[left],a[j]);
        quickSort(a,left,j-1);
        quickSort(a,j+1,right);
    }
    return 1;
}
int insertData() //插入
{
    int data,index,i;
    cout<<"请输入插入的数据："<<'\n';
    cin>>data;
    cout<<"请输入插入位置(数组位置从0开始)："<<'\n';
    cin>>index;
    if(len-1<index) //插入位置比数组大，插在最后
    {
        len++;
        int* tem = new int[len];
        for(i=0;i<len-1;i++) tem[i]=arr[i];
        tem[i]=data;
        cout<<"插入成功"<<'\n';
        delete[] arr;
        arr=tem;
        return 1;
    }
    len++;
    int* tem = new int[len];
    for(i=0;i<index;i++)
    {
        tem[i]=arr[i];
    }
    tem[i]=data;  //插入数据
    i++;
    for(;i<len;i++)
    {
        tem[i]=arr[i-1];
    }
    delete [] arr;
    arr=tem;
    cout<<"插入成功"<<'\n';
    return 1;
}
int erase()  //删除
{
    if(len==0)
    {
        cout<<"数组为空"<<'\n';
        return 1;
    }
    int index,i;
    cout<<"请输入删除位置(数组位置从0开始)："<<'\n';
    cin>>index;
    if(len-1<index)
    {
        cout<<"无指定位置元素"<<'\n';
        return 0;
    }
    len--;
    int* tem = new int[len];
    for(i=0;i<index;i++)
    {
        tem[i]=arr[i];
    }
    for(;i<len;i++)
    {
        tem[i]=arr[i+1];
    }
    delete [] arr;
    arr=tem;
    cout<<"删除成功!"<<'\n';
    return 0;
}
int outTheNum() //输出指定元素
{
    if(len==0)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int index,i;
    cout<<"请输入指定输出位置(数组位置从0开始)："<<'\n';
    cin>>index;
    if(index>len-1)
    {
        cout<<"无指定位置元素"<<'\n';
        return 0;
    }
    cout<<"指定位置元素为："<<arr[index]<<'\n';
    return 1;
}
int Sum() //求和
{
    if(len==0)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int num,sum=0,i;
    cout<<"请输入求和数组元素个数："<<'\n';
    reset: cin>>num;
    if(num>len)
    {
        cout<<"请重新输入"<<'\n';
        goto reset;
    }
    for(i=0;i<num;i++)
    {
        sum+=arr[i];
    }
    cout<<"求和结果为："<<sum<<'\n';
    return 1;
}
int search() //查找
{
    if(len==0)
    {
        cout<<"数组为空"<<'\n';
        return 0;
    }
    int num,i,count=0;
    cout<<"请输入查找元素："<<'\n';
    cin>>num;
    int* tem = new int[len];
    for(i=0;i<len;i++)
    {
        if(arr[i]==num)
        {
            tem[count++]=i;
        }
    }
    if(count==0)
    {
        cout<<"数组中无该元素"<<'\n';
        return 0;
    }
    else if(count==1)
    {
        cout<<"数组中有"<<count<<"个该元素"<<'\n'<<"位于第"<<tem[0]<<"位置(数组位置从0开始)"<<'\n';
    }
    else
    {
        cout<<"数组中有"<<count<<"个该元素"<<'\n'<<"分别位于";
        for(i=0;i<count;i++)
        {
            cout<<"第"<<tem[i]<<",";
        }
        cout<<"位置(数组位置从0开始)"<<'\n';
    }
    delete[] tem;
    return 1;
}
int main()
{
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
            delete [] arr;
            cout<<"bye~"<<'\n';
            break;
        } 
        if(oper=='1') inputData();
        if(oper=='2')
        {
            quickSort(arr,0,len-1);
            cout<<"排序完成"<<'\n';
        } 
        if(oper=='3') insertData();
        if(oper=='4') search();
        if(oper=='5') erase();
        if(oper=='6') output();
        if(oper=='7') outTheNum();
        if(oper=='8') Sum();
    }
    return 0;
}