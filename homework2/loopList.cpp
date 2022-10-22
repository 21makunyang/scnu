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
    friend class LoopList;
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

class LoopList
{
private:
    Node *head;
    Node *rear;

public:
    LoopList(/* args */);
    ~LoopList();
    void output();
    void insert(float newNum);
    bool removeMin();
    bool deleteOutOfInterval(float min, float max);
};

LoopList::LoopList(/* args */)
{
    head = nullptr;
    rear = nullptr;
}

LoopList::~LoopList()
{
    Node *tem;
    while (head->next != head)
    {
        tem = head->next;
        delete head;
        rear->next = tem;
        head = tem;
    }

    if (head != nullptr)
    {
        delete head;
        head = nullptr;
    }
}
void LoopList::insert(float newNum)
{
    if (head == nullptr)
    {
        head = new Node(newNum);
        head->next = head;
        rear = head;
        return;
    }

    rear->next = new Node(newNum);
    rear = rear->next;
    rear->next = head;
    return;
}

void LoopList::output()
{
    if (head == nullptr)
    {
        return;
    }
    
    cout << head->num << " ";
    Node *cur = head->next;
    while (cur != head)
    {
        cout << cur->num << " ";
        cur = cur->next;
    }
    cout<<'\n';
    return;
}
bool LoopList::deleteOutOfInterval(float min, float max)
{
    if (min > max)
        return false;
    if (head == nullptr)
        return false;
    Node *cur = head->next, *preOfCur = head;
    while (cur != head)
    {
        if (cur->num < min || cur->num > max)
        {
            preOfCur->next = cur->next;
            if (cur == rear)
            {
                rear = preOfCur;
                rear->next = head;
            }
            delete cur;
            cur = preOfCur;
        }
        preOfCur = cur;
        cur = cur->next;
    }

    if (head->num < min || head->num > max)
    {
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            head->next = nullptr;
            return true;
        }
        cur = head->next;
        delete head;
        rear->next = cur;
        head = cur;
    }
    return true;
}
bool LoopList::removeMin()
{
    if (head == nullptr)
        return false;
    if (head->next == head)
    {
        delete head;
        rear=head = nullptr;
        return true;
    }
    Node *cur = head, *preOfMin = head;
    float min = head->num;
    while (cur->next != head)
    {
        if (cur->next->num < min)
        {
            min = cur->next->num;
            preOfMin = cur;
        }
        cur = cur->next;
    }
    Node *tem;
    if (head->num <= min || preOfMin == head)
    {
        tem = head->next;
        rear->next = tem;
        delete head;
        head = tem;
        return true;
    }

    tem = preOfMin->next->next;
    delete preOfMin->next;
    preOfMin->next = tem;
    return true;
}
int main()
{
    LoopList lp;
    lp.insert(1);
    lp.insert(2);
    lp.insert(3);
    lp.insert(4);
    lp.insert(5);
    lp.output();
    // lp.deleteOutOfInterval(3, 4);
    lp.removeMin();
    lp.output();
    return 0;
}