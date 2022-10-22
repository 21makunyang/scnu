#include <bits/stdc++.h>

using namespace std;

template <class T>
struct TreeNode
{
    T data;
    TreeNode<T> *firstChild, *nextSibling;
    TreeNode(T value = 0, TreeNode<T> *fc = NULL, TreeNode<T> *ns = NULL) : data(value), firstChild(fc), nextSibling(ns) {}
};

template <class T>
class Tree
{
private:
    TreeNode<T> *root;
    void createTree(T f[], T c[], TreeNode<T> *&t);
    void printTree(TreeNode<T> *t, int k);
    void turnOver(TreeNode<T> *subTree);
public:
    Tree(/* args */) { root = NULL; };
    TreeNode<T> *getRoot() { return root; };
    bool isEmpty() { return root == NULL; };
    void createTree(T f[], T c[]) { createTree(f, c, root); };
    void printTree();
    void turnOver(){turnOver(root);};
};
#define maxSize 30
template <class T>
void Tree<T>::createTree(T f[], T c[], TreeNode<T> *&t)
{
    int n, i, k;
    T father, child;
    if (f[0] != '^')
    {
        cout << "false\n";
        return;
    }
    if (c[0] == '^')
    {
        t = NULL;
        return;
    }
    TreeNode<T> **pointer = new TreeNode<T> *[maxSize];
    TreeNode<T> **lastChild = new TreeNode<T> *[maxSize];
    pointer[0] = new TreeNode<T>;
    pointer[0]->data = c[0];
    pointer[0]->firstChild = pointer[0]->nextSibling = NULL;
    i = 1;
    n = 1;
    father = f[i];
    child = c[i];
    while (father != '^' && child != '^')
    {
        pointer[n] = new TreeNode<T>;
        pointer[n]->data = child;
        pointer[n]->firstChild = pointer[n]->nextSibling = NULL;
        for (k = n - 1; k >= 0; k--)
        {
            if (pointer[k]->data == father)
                break;
        }
        if (pointer[k]->firstChild == NULL)
        {
            pointer[k]->firstChild = pointer[n];
            lastChild[k] = pointer[n];
        }
        else
        {
            lastChild[k]->nextSibling = pointer[n];
            lastChild[k] = pointer[n];
        }
        n++;
        father = f[++i];
        child = c[i];
    }
    t = pointer[0];
    delete[] pointer;
    delete[] lastChild;
}
template <typename T>
void Tree<T>::printTree(TreeNode<T> *t, int k)
{
    for (int i = 0; i < k; i++)
    {
        cout << " ";
    }
    if (t != NULL)
    {
        cout << t->data << '\n';
        for (TreeNode<T> *p = t->firstChild; p != NULL; p = p->nextSibling)
            printTree(p, k + 5);
    }
}
template <typename T>
void Tree<T>::printTree()
{
    printTree(root, 1);
    TreeNode<T>* t = root->nextSibling;
    while(t){
        printTree(t,1);
        t=t->nextSibling;
    }
}
template<typename T>
void Tree<T>::turnOver(TreeNode<T> *subTree){
    if(subTree == NULL)
        return;
    TreeNode<T>* tem = subTree->firstChild;
    subTree->firstChild = subTree->nextSibling;
    subTree->nextSibling = tem;
}
int main()
{
    Tree<char> t;
    char f[] = "^RRRAACFFF^";
    char c[] = "RABCDEFGHK^";
    t.createTree(f, c);
    cout<<"交换前：\n";
    t.printTree();
    cout<<"交换后：\n";
    t.turnOver();
    t.printTree();
    return 0;
}