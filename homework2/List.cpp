#include <bits/stdc++.h>
using namespace std;
class Node
{
private:
    float num;
    Node *next;

public:
    Node();
    Node(float newNum);
    void setNum(float newNum)
    {
        num = newNum;
    };
    float getNum()
    {
        return num;
    };
    friend class List;
};
Node::Node(float newNum)
{
    num = newNum;
    next = nullptr;
}
Node::Node()
{
    next = nullptr;
}

class List
{
private:
    Node *head;
    Node *rear;

public:
    void insert(float newNum);
    void reverse();
    void show();
    bool pop_back();
    bool deleteMin();
    bool empty()
    {
        return (head == nullptr) ? 1 : 0;
    };
    bool deleteInterval(float min, float max);
    List();
    ~List();
};
List::List()
{
    head = nullptr;
    rear = nullptr;
}
List::~List()
{
    Node *node;
    while (head->next != nullptr)
    {
        node = head->next;
        delete head;
        head = node;
    }
    if (head != nullptr)
    {
        delete head;
    }
}
void List::insert(float newNum)
{
    Node *newNode = new Node(newNum);

    if (head == nullptr)
    {
        rear = head = newNode;
        newNode = nullptr;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    newNode = nullptr;
    return;
}
void List::show()
{
    if (head == nullptr)
        return;
    for (Node *cur = head; cur != nullptr; cur = cur->next)
    {
        cout << cur->num << " ";
    }
    cout << '\n';
}
bool List::pop_back()
{
    if (head == nullptr)
        return false;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return true;
    }
    Node *tem = head;
    Node *cur = head;
    for (; cur->next != nullptr; cur = cur->next)
    {
        tem = cur;
    }
    delete cur;
    cur = nullptr;
    tem->next = nullptr;
    rear = tem;
    return true;
}
void List::reverse()
{
    if (head == nullptr)
        return;
    Node *newHead = new Node(rear->num);
    pop_back();
    Node *newNode, *cur = newHead;
    while (!empty())
    {
        newNode = new Node(rear->num);
        pop_back();
        cur->next = newNode;
        cur = cur->next;
    }
    head = newHead;
}
bool List::deleteMin()
{
    if (head == nullptr)
        return false;

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return true;
    }

    float min = head->num;
    Node *pMin = head, *tem = head, *preOfPMin = head;
    for (Node *cur = head->next; cur != nullptr; cur = cur->next)
    {
        if (cur->num < min)
        {
            preOfPMin = tem;
            pMin = cur;
            min = cur->num;
        }
        tem = cur;
    }
    preOfPMin->next = pMin->next;
    delete pMin;
    pMin = nullptr;
    return true;
}

bool List::deleteInterval(float min, float max)
{
    if (max < min)
        return false;
    if (head == nullptr)
        return false;

    if (head->next == nullptr && (head->num> min && head->num < max))
    {
        delete head;
        head = nullptr;
        return true;
    }

    Node *tem = head;
    for (Node *cur = head->next; cur != nullptr; cur = cur->next)
    {
        if (cur->num > min && cur->num < max)
        {
            tem->next = cur->next;
            delete cur;
            cur = tem;
        }
        tem = cur;
    }
    if(head->num > min && head->num < max){
        tem = head->next;
        delete head;
        head = tem;
    }
    return true;
}
int main()
{
    List list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.show();
    // list.reverse();
    // list.show();
    list.deleteInterval(2, 5);
    list.show();
}