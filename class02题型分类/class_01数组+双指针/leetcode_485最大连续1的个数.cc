/*
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

 

示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
示例 2:

输入：nums = [1,0,1,1,0,1]
输出：2

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max, one_max;

        one_max = 0;
        max = 0;
        for (auto num : nums)
        {
            // printf(" %d, ", num);
            if (num == 1)
            {
                one_max++;
            }
            else
            {
                if (one_max > max)
                {
                    max = one_max;
                }
                one_max = 0;
            }
        }

        if (one_max > max)
        {
            max = one_max;
        }
        // printf("\n");

        return max;
    }
};

int
main(int argc, char **agrv)
{
    int ret;
    Solution s;
    vector<int> nums;

    nums = { 1, 1, 0, 1, 1, 1 };
    ret = s.findMaxConsecutiveOnes(nums);
    cout << ret << endl;

    // nums = { 1, 0, 1, 1, 0, 1 };
    // ret = s.findMaxConsecutiveOnes(nums);
    // cout << ret << endl;
    // print_vector2(ret);

    return 0;
}