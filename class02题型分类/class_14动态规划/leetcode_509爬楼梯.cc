/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？


示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶
示例 2：

输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶


提示：

1 <= n <= 45

*/

#include <iostream>
#include <vector>
using namespace std;

// 递归的方式会重复计算，导致超时
// class Solution
// {
// public:
//     int
//     climbStairs(int n)
//     {
//         int i, last, curr, sum;
//         if (1 == n) return 1; // 到达第一阶台阶只有一种方法
//         if (2 == n) return 2;

//         last = 1;
//         curr = 2;
//         for (i = 3; i <= n; i++)
//         {
//             sum = last + curr;
//             last = curr;
//             curr = sum;
//         }

//         return sum;
//     }
// };



class Solution
{
public:
    int
    climbStairs(int n)
    {
        vector<int> dp(n + 1);
        if (n == 1) return 1;
        if (n == 2) return 2;

        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// int
// main(int argc, char **agrv)
// {
//     Solution s;
//     int target;

//     cout << s.climbStairs(2) << endl;

//     cout << s.climbStairs(3) << endl;
// }


int main()
{
    Solution s;
    // cout << "s.climbStairs(1): " << s.climbStairs(1) << endl;
    // cout << "s.climbStairs(2): " << s.climbStairs(2) << endl;
    // cout << "s.climbStairs(3): " << s.climbStairs(3) << endl;
    cout << "s.climbStairs(4): " << s.climbStairs(4) << endl;
    // cout << "s.climbStairs(5): " << s.climbStairs(5) << endl;
}