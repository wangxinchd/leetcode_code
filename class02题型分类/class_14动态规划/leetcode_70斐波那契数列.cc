/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。




示例 1：

输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例 2：

输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
示例 3：

输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3


提示：

1 <= n <= 45

*/


#include <iostream>
#include <vector>
using namespace std;



// class Solution {
// public:
//     int fib(int n) {
//         int i, last, curr, sum;
//         if (0 == n) return 0;
//         if (1 == n) return 1;

//         last = 0;
//         curr = 1;
//         for (i = 2 ; i <= n; i++)
//         {
//             sum = last + curr;
//             last = curr;
//             curr = sum;
//         }

//         return sum;
//     }
// };

// class Solution {  // 2024-02-29 练习
// public:
//     int fib(int n) {
//         vector <int> dp(n+1);
//         dp[0] = 0;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

class Solution {  // 2024-02-29 练习
public:
    int fib(int n) {
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


int
main(int argc, char **agrv)
{
    Solution s;
    int target;

    cout << s.fib(2) << endl;
    cout << s.fib(3) << endl;
    cout << s.fib(4) << endl;
    cout << s.fib(5) << endl;
}

// 递归的方式会重复计算，导致超时
