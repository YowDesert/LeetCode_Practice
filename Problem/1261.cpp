#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements
{
    unordered_set<int> recoveredValues;

public:
    void recoverNode(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        recoveredValues.insert(root->val);
        if (root->left)
        {
            root->left->val = root->val * 2 + 1;
            recoverNode(root->left);
        }
        if (root->right)
        {
            root->right->val = root->val * 2 + 2;
            recoverNode(root->right);
        }
    }

    FindElements(TreeNode *root)
    {
        root->val = 0;
        recoverNode(root);
    }

    bool find(int target)
    {
        return recoveredValues.count(target);
    }
};