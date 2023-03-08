#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    unsigned long long weight;
    TreeNode():weight(0),left(nullptr),right(nullptr){};
    TreeNode(unsigned long long wei) : weight(wei), left(nullptr), right(nullptr) {}
    bool operator<(TreeNode *&obj)
    {
        if (obj == nullptr)
            return false;
        return this->weight < obj->weight;
    }
    void operator=(const TreeNode &obj){
        this->weight = obj.weight;
        this->left = obj.left;
        this->right = obj.right;
    }
    
};
bool comp(TreeNode *a, TreeNode *b)
{
    if (a == nullptr && b == nullptr)
        return true;
    if (a == nullptr || b == nullptr)
        return false;
    return a->weight < b->weight;
}
void del(TreeNode*& p){
    if(p!=NULL){
        del(p->left);
        del(p->right);
        delete p;
    }
}
int main()
{
    TreeNode * newNode =NULL,*p = NULL;
    int n;
    cin >> n;
    queue<TreeNode *> que;
    unsigned long long wei;
    for (int i = 0; i < n; i++)
    {
        cin >> wei;
        que.push(new TreeNode(wei));
    }
    sort(&que.front(), &que.back(), comp);
    wei = 0;
    while(que.size() != 1){
        p= que.front();
        que.pop();
        wei+=p->weight+que.front()->weight;
        newNode= new TreeNode;
        newNode->weight =p->weight+que.front()->weight;
        newNode->left = p;
        newNode->right = que.front();
        que.pop();
        que.push(newNode);
        sort(&que.front(), &que.back(), comp);
    }
    
    cout<<wei;
    p = que.front();
    del(p);
    return 0;
}