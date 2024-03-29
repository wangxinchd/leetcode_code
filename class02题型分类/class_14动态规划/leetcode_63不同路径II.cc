/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。


示例 1：

输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：

输入：obstacleGrid = [[0,1],[0,0]]
输出：1


*/


#include <iostream>
#include <vector>
using namespace std;


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int i, j;
//         bool has_obstacle;
//         int m = (int) obstacleGrid.size();
//         int n = (int) obstacleGrid[0].size();
//         vector<vector<int>> dp(m,  vector<int>(n));

//         has_obstacle = false;
//         for (i = 0; i < m; i++)
//         {
//             if (obstacleGrid[i][0]) has_obstacle = true;

//             if (has_obstacle)
//             {
//                 dp[i][0] = 0;
//             }
//             else
//             {
//                 dp[i][0] = 1;
//             }
//         }

//         has_obstacle = false;
//         for (j = 0; j < n; j++)
//         {
//             if (obstacleGrid[0][j]) has_obstacle = true;

//             if (has_obstacle)
//             {
//                 dp[0][j] = 0;
//             }
//             else
//             {
//                 dp[0][j] = 1;
//             }
//         }

//         for (i = 1; i < m; i++)
//         {
//             for (j = 1; j < n; j++)
//             {
//                 if (!obstacleGrid[i][j])
//                 {
//                     dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//                 }
//             }
//         }

//         return dp[m - 1][n - 1];
//     }
// };


void print_vector(vector<vector<int>> v)
{
    for (auto a: v)
    {
        for (auto b :a)
        {
            printf("%d, ", b);
        }
        printf("\n");
    }
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
            {
                dp[i][0] = 1;
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0)
            {
                dp[0][j] = 1;
            }
            else
            {
                break;
            }
        }

        // print_vector(dp);

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};



int
main(int argc, char **agrv)
{
    Solution s;
    vector<vector<int>> obstacleGrid;

    obstacleGrid = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

    obstacleGrid = { { 0, 1 }, { 0, 0 } };
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;


    obstacleGrid = { { 0, 0 }, { 0, 0 } };
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

}