#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

class Solution
{
public:
    int preIndex = 0;
    unordered_map<int, int> postMap;
    TreeNode *recursiveTree(vector<int> &preorder, vector<int> &postorder, int postStart, int postEnd)
    {
        if (postStart > postEnd)
        {
            return nullptr;
        }

        int PreVal = preorder[preIndex++];
        TreeNode *root = new TreeNode(PreVal);

        if (postStart == postEnd)
            return root;

        int leftRootVal = preorder[preIndex];
        int leftRootIndexInPost = postMap[leftRootVal];

        root->left = recursiveTree(preorder, postorder, postStart, leftRootIndexInPost);
        root->right = recursiveTree(preorder, postorder, leftRootIndexInPost + 1, postEnd - 1);

        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); i++)
        {
            postMap[postorder[i]] = i;
        }

        return recursiveTree(preorder, postorder, 0, postorder.size() - 1);
    }
};