/*
给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：

nums[0] = 0
nums[1] = 1
当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
返回生成数组 nums 中的 最大 值。

 

示例 1：

输入：n = 7
输出：3
解释：根据规则：
  nums[0] = 0
  nums[1] = 1
  nums[(1 * 2) = 2] = nums[1] = 1
  nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
  nums[(2 * 2) = 4] = nums[2] = 1
  nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
  nums[(3 * 2) = 6] = nums[3] = 2
  nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
示例 2：

输入：n = 2
输出：1
解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
示例 3：

输入：n = 3
输出：2
解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
 

提示：

0 <= n <= 100

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    dp[i] 表示 返回生成数组值
    dp[偶数] = dp[偶数/2]
    dp[奇数] = dp[(奇数-1)/2] + dp[(奇数-1)/2 + 1]


    dp[0] = 0
    dp[1] = 1
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        int i = 0;
        vector<int> dp(n + 1);

        if (n == 0) return 0;
        if (n == 1) return 1;

        dp[0] = 0;
        dp[1] = 1;

        for (i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = dp[i / 2];
            }
            else
            {
                dp[i] = dp[(i - 1) / 2] + dp[(i - 1) / 2 + 1];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    int target;

    cout << s.getMaximumGenerated(1) << endl;
    cout << s.getMaximumGenerated(2) << endl;
    cout << s.getMaximumGenerated(3) << endl;
    cout << s.getMaximumGenerated(4) << endl;
    cout << s.getMaximumGenerated(5) << endl;
    cout << s.getMaximumGenerated(6) << endl;
    cout << s.getMaximumGenerated(7) << endl;

    cout << s.getMaximumGenerated(15) << endl;
}

// 递归的方式会重复计算，导致超时
