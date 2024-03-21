/**
给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）

 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。

 

示例 1：

输入：graph = [[1,2],[3],[3],[]]
输出：[[0,1,3],[0,2,3]]
解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3


输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

*/

#include <iostream>
#include <vector>
#include <deque>


using namespace std;

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> stk;

//     void dfs(vector<vector<int>>& graph, int x, int n) {
//         if (x == n) {
//             ans.push_back(stk);
//             return;
//         }
//         for (auto& y : graph[x]) {
//             stk.push_back(y);
//             dfs(graph, y, n);
//             stk.pop_back();
//         }
//     }

//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         stk.push_back(0);
//         dfs(graph, 0, graph.size() - 1);
//         return ans;
//     }
// };

class Solution {
public:
    // 记录所有路径
    vector<vector<int>> res;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        deque<int> path;
        traverse(graph, 0, path);
        return res;
    }

    /* 图的遍历框架 */
    void traverse(vector<vector<int>>& graph, int s, deque<int>& path) {

        // 添加节点 s 到路径
        path.push_back(s);

        int n = graph.size();
        if (s == n - 1) {
            // 到达终点
            res.push_back(vector<int>(path.begin(), path.end()));
            path.pop_back();
            return;
        }

        // 递归每个相邻节点
        for (int v : graph[s]) {
            traverse(graph, v, path);
        }

        // 从路径移出节点 s
        path.pop_back();
    }
};

void
print_vector(vector<vector<int>> &ret)
{
    for (auto a: ret)
    {
        for (auto b: a)
        {
            printf("%d, ", b);
        }
        printf("\n");
    }
}

int
main()
{
    vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};

    Solution s;
    vector<vector<int>> ret = s.allPathsSourceTarget(graph);
    print_vector(ret);

    return 0;
}