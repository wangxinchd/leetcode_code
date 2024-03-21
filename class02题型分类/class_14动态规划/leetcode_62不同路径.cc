/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？



示例 1：

输入：m = 3, n = 7
输出：28

示例 2：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下


*/


#include <iostream>
#include <vector>
using namespace std;



// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         int i, j;
//         vector<vector<int>> vec(m, vector<int>(n));

//         for (i = 0; i < m; i++)
//         {
//             vec[i][0] = 1;
//         }

//         for (i = 0; i < n; i++)
//         {
//             vec[0][i] = 1;
//         }

//         for (i = 1; i < m; i++)
//         {
//             for (j = 1; j < n; j++)
//             {
//                 vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
//                 printf("vec[%d][%d] = %d \n", i, j, vec[i][j]);
//             }
//         }

//         return vec[m - 1][n - 1];
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int
main(int argc, char **agrv)
{
    Solution s;

    cout << s.uniquePaths(3, 7) << endl;

    cout << s.uniquePaths(3, 2) << endl;
    cout << s.uniquePaths(2, 2) << endl;

}