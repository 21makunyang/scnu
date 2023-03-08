#include <bits/stdc++.h>
using namespace std;

void siftDown(int arr[], int len, int start, int stop)
{
    int child = start * 2 + 1, temp = arr[start], par = start;
    while (child <= stop)
    {
        //找出孩子中较大的一个的下标
        if (child < stop && arr[child] < arr[child + 1])
            child++;
        //若父节点比左右孩子都大则结束
        if (temp >= arr[child])
            break;
        //孩子上移
        arr[par] = arr[child];
        par = child;
        child = par * 2 + 1;
    }
    //将start对应的值放到合适位置
    arr[par] = temp;
}
void heapSort(int arr[], int len)
{
    if (len == 0 || len == 1)
        return;
    for (int i = len - 1; i >= 0; i--)
    {
        siftDown(arr, len, i, len - 1);
    }
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        siftDown(arr, len, 0, i - 1);
    }
}
int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    heapSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}