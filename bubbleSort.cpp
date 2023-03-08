#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *next;
    int data;
};

void bubbleSort(Node *&begin, Node *&end)
{
    if (begin == nullptr)
        return;
    Node *tem = begin, *tem2 = begin;
    int swTemp;

    bool sorted = true;
    while (tem != end)
    {
        sorted = true;
        while (tem2->next != end)
        {

            if (tem2->data > tem2->next->data)
            {
                sorted = false;
                swTemp = tem2->data;
                tem2->data = tem2->next->data;
                tem2->next->data = swTemp;
            }
            tem2 = tem2->next;
        }
        if(sorted) return;
        tem = tem->next;
        tem2 = begin;
    }
}

int main()
{
    Node* n1 = new Node,*n2 = new Node,*n3 =new Node;
    n1->data = 1;
    n2->data = 3;
    n3->data = 2;
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;
    bubbleSort(n1,n3->next);
    Node* tem = n1;
    while (tem!=nullptr)
    {
        cout<<tem->data<<" ";
        tem = tem->next;
    }
    cout<<'\n';
    delete n1;
    delete n2;
    delete n3;
    return 0;
}