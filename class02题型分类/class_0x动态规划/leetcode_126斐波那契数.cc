/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

答案需要取模 1e9+7(1000000007) ，如计算初始结果为：1000000008，请返回 1。

 

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

0 <= n <= 100

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fib(int n) {
        int i;
        int MOD = 1000000007;
        vector<int> dp(n+1);

        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        dp[0] = 0;
        dp[1] = 1;

        for (i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
    
        return dp[n];
    }
};

int
main(int argc, char **agrv)
{
    int ret;
    Solution s;
    int num;

    num = 4;
    ret = s.fib(num);
    cout << ret << endl;

    num = 25;
    ret = s.fib(num);
    cout << ret << endl;

    num = 37;
    ret = s.fib(num);
    cout << ret << endl;

    return 0;
}