
/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。


示例 1：
                 1(A)
                  \
                   2(B)
                  /
                 3(C)
输入：root = [1,null,2,3]
输出：[3,2,1]

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

class Solution
{
public:
    vector<int>
    _postorder_Traversal(vector<int> &ret, TreeNode *root)
    {
        // vector<int> ret;
        if (root != nullptr)
        {
            _postorder_Traversal(ret, root->left);
            _postorder_Traversal(ret, root->right);
            printf("%d ", root->val);
            ret.push_back(root->val);
        }
        return ret;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        _postorder_Traversal(ret, root);
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

    ret = s.postorderTraversal(&A);
    print_vector(ret);

    return 0;
}