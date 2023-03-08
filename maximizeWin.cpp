#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> arr;
    void midOrder(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        midOrder(node->left);
        arr.push_back(node->val);
        midOrder(node->right);
    }
    bool isValidBST(TreeNode *root)
    {
        midOrder(root);
        if (arr.size()<=1){
            return true;
        }
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i]<=arr[i-1]){
                return false;
            }
        }
        return true;
    }
    
};

int main()
{
    int num[] = {1, 1, 2, 2, 3, 3, 5};
    vector<int> nums{1, 1, 2, 2, 3, 3, 5};
    Solution so;
    cout << '\n';
}