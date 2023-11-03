/*
题目：
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
提示：

3 <= arr.length <= 105
0 <= arr[i] <= 106
题目数据保证 arr 是一个山脉数组

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int middle, right, left;

        left = 0;
        right = (int) nums.size() - 1;

        while (left <= right)
        {
            middle = (left + right) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> arr;

    // 测试1
    arr = { -1,0,3,5,9,12 };
    cout << solution.search(arr, 9) << endl;

    // 测试2
    arr = { -1,0,3,5,9,12 };
    cout << solution.search(arr, 2) << endl;


    return 0;
}