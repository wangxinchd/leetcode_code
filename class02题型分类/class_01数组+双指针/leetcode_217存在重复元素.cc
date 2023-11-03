/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

示例 1：

输入：nums = [1,2,3,1]
输出：true
示例 2：

输入：nums = [1,2,3,4]
输出：false
示例 3：

输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true

提示：

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 重复元素，直接哈希

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> uset;

        for (auto n: nums)
        {
            if (uset.find(n) == uset.end())
            {
                uset.insert(n);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    int target;
    vector<int> height;

    // 测试01
    height = {1,2,3,1};
    cout << s.containsDuplicate(height) << endl;

    // 测试02
    height = {4,2,0,3,2,5};
    cout << s.containsDuplicate(height) << endl;

    // 测试03
    height = {4,2,3};
    cout << s.containsDuplicate(height) << endl;

}