/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

void
print_vector(vector<int> v)
{
    cout << "[";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> arr(nums.size());

        int left, right, n;
        double left_value, right_value;

        left = 0;
        right = (int) nums.size() - 1;
        n = right;
        for (; left <= right;)
        {
            left_value = nums[left] * nums[left];
            right_value = nums[right] * nums[right];

            if (left_value >= right_value)
            {
                arr[n] = left_value;
                left++;
            }
            else
            {
                arr[n] = right_value;
                right--;
            }
            n--;
        }
        return arr;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> s, ret;

    s = { -4, -1, 0, 3, 10 };
    ret = solution.sortedSquares(s);

    print_vector(ret);
    return 0;
}