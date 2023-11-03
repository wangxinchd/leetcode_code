
/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。


示例 1：
                 1(A)
                  \
                   2(B)
                  /
                 3(C)
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void
print_vector(vector<int> v)
{
    cout << "打印一维数组\n";
    cout << "[";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

void
insertNode(TreeNode *parent, TreeNode *Lchird, TreeNode *Rchild)
{
    parent->left = Lchird;
    parent->right = Rchild;
}

// class Solution
// {
// public:
//     vector<int>
//     pTraversal(vector<int> &ret, TreeNode *root)
//     {
//         // vector<int> ret;
//         if (root != nullptr)
//         {
//             printf("%d ", root->val);
//             ret.push_back(root->val);
//             pTraversal(ret, root->left);
//             pTraversal(ret, root->right);
//         }
//         return ret;
//     }

//     vector<int>
//     preorderTraversal(TreeNode *root)
//     {
//         vector<int> ret;
//         pTraversal(ret, root);
//         return ret;
//     }
// };

// 利用栈进行递归前序遍历
class Solution
{
public:

    vector<int>
    preorderTraversal(TreeNode *root)
    {
        TreeNode *node;
        vector<int> ret;
        stack <TreeNode *> st;

        if (root != nullptr)
        {
            st.push(root);
            while (!st.empty())
            {
                node = st.top();
                st.pop();

                if (node != nullptr)
                {
                    ret.push_back(node->val);
                    st.push(node->right); // 先入右子树，再入左子树【栈是先进后出】
                    st.push(node->left);
                }
                // print_vector(ret);
            }
        }

        return ret;
    }
};


int
main()
{
    Solution s;
    vector<int> ret;
    TreeNode A(1);
    TreeNode B(2);
    TreeNode C(3);

    insertNode(&A, nullptr, &B);
    insertNode(&B, &C, nullptr);

    ret = s.preorderTraversal(&A);
    print_vector(ret);

    return 0;
}