/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。



示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5


提示：

树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
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
class Solution {
public:
    int
    minDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;

        queue < pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int depth = q.front().second;
            if (node->left == nullptr && node->right == nullptr)
            {
                return depth;
            }
            q.pop();

            if (node->left != nullptr)
            {
                q.push(make_pair(node->left, depth+1));
            }
            if (node->right != nullptr)
            {
                q.push(make_pair(node->right, depth+1));
            }
        }

        return 0;
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
    cout << "s.maxDepth() = " << s.minDepth(&A) << endl;

    return 0;
}