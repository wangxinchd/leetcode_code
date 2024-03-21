/*
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：3
示例 2：

输入：root = [1,null,2]
输出：2

提示：
树中节点的数量在 [0, 104] 区间内。
-100 <= Node.val <= 100

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




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

// 实现了一层一层的遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue <TreeNode *> Q;
        Q.push(root);

        int ans = 0;
        while (!Q.empty())
        {
            int q_size = Q.size();
            while (q_size > 0)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left)
                {
                    Q.push(node->left);
                }
                if (node->right)
                {
                    Q.push(node->right);
                }
                q_size -= 1;
            }
            ans += 1;
        }

        return ans;
    }
};


int main()
{
    vector <int> input = {3, 9, 20, 0, 0, 15, 7};

    TreeNode E(7);
    TreeNode D(15);
    TreeNode C(20, &D, &E);
    TreeNode B(9);
    TreeNode A(3, &B, &C);

    Solution s;
    cout << "s.maxDepth() = " << s.maxDepth(&A) << endl;

    return 0;
}