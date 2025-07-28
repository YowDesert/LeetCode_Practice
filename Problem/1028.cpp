#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//   Definition for a binary tree node.
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
    TreeNode *recoverFromPreorder(string traversal)
    {
        stack<TreeNode *> st;
        int i = 0;
        while (i < traversal.size())
        {
            int depth = 0;
            while (i < traversal.size() && traversal[i] == '-')
            {
                depth++;
                i++;
            }
            int number = 0;
            while (i < traversal.size() && isdigit(traversal[i]))
            {
                number = number * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode *Node = new TreeNode(number);

            while (st.size() > depth)
            {
                st.pop();
            }

            if (!st.empty())
            {
                if (!st.top()->left)
                    st.top()->left = Node;
                else
                    st.top()->right = Node;
            }

            st.push(Node);
        }
        while (st.size() > 1)
            st.pop();
        return st.top();
    }
};