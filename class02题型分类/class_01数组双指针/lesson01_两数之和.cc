/*
题目：
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int>
    twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        int i, j, len;
        i = j = 0;
        len = ( int )nums.size();
        for (i = 0; i < len - 1; i++)
        {
            for (j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    int target;
    vector<int> nums, ret;

    // 测试01
    nums = {2, 7, 11, 15};
    target = 9;

    ret = s.twoSum(nums, target);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;

    // 测试02
    nums.clear();
    nums = { 3, 2, 4 };
    target = 6;

    ret = s.twoSum(nums, target);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;

    // 测试03
    nums.clear();
    nums = { 3, 3 };
    target = 6;

    ret = s.twoSum(nums, target);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;

    // 测试04
    nums.clear();
    nums = { 2, 5, 5, 11 };
    target = 10;

    ret = s.twoSum(nums, target);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
}