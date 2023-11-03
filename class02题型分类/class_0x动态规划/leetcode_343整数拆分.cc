/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。


示例 1:

输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。



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

class Solution {
public:
    int integerBreak(int n) {
        int i, j; 
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (i = 3; i <= n; i++)
        {
            for (j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                // dp[i] = max(j * (i - j), j * dp[i - j]);
            }
        }
        print_vector(dp);

        return dp[n];
    }
};

int
main(int argc, char **agrv)
{
    Solution s;

    cout << s.integerBreak(10) << endl;
    cout << s.integerBreak(15) << endl;
    cout << s.integerBreak(2) << endl;

}