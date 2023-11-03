/*
题目：
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0


*/
#include <iostream>
#include <stack>
#include <vector>

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
    // int sum_vector(vector<int> &nums, int start, int end)
    // {
    //     int sum = 0;
    //     for (int i = start; i <= end; i++)
    //     {
    //         sum += nums[i];
    //     }
    //     return sum;
    // }

    int
    minSubArrayLen(int target, vector<int> &nums)
    {
        // vector<int> res(0);
        int min_len = INT32_MAX;
        // printf("sum : %d\n", sum_vector(nums, 0, ( int )nums.size() - 1));

        int front, end, len, i, sum;

        len = (int) nums.size();
        front = end = 0;

        sum = nums[front];
        for (;end < len;)
        {
            // printf("{%d, %d}, sum %d\n", front, end, sum);

            if (sum >= target)
            {
                // printf("target = sum {%d, %d}, sum %d\n", front, end, sum);

                if ((end - front + 1) < min_len)
                {
                    min_len = end - front + 1;
                    // res.clear();
                    // for (i = 0; i < end - front + 1; i++)
                    // {
                    //     res.push_back(nums[front + i]);
                    // }
                    // print_vector(res);
                    // min_len = res.size();
                }
                if (front < end)
                {
                    front++;
                    sum -= nums[front - 1];
                }
                else if (front == end)
                {
                    end++;
                    if (end < len)
                    {
                        sum += nums[end];
                    }
                }
            }
            else
            {
                end++;
                if (end < len)
                {
                    sum += nums[end];
                }
            }
        }

        return min_len == INT32_MAX? 0: min_len;
    }
};



int
main(int argc, char **agrv)
{
    Solution solution;
    printf("======1======\n");
    vector<int> nums = { 2, 3, 1, 2, 4, 3 };
    cout << solution.minSubArrayLen(7, nums) << endl;

    printf("======2======\n");
    nums = { 1, 4, 4 };
    cout << solution.minSubArrayLen(4, nums) << endl;

    printf("======3======\n");
    nums = { 1, 1, 1, 1, 1, 1, 1, 1 };
    cout << solution.minSubArrayLen(11, nums) << endl;

    printf("======4======\n");
    nums = {1,2,3,4,5};
    cout << solution.minSubArrayLen(11, nums) << endl;

    return 0;
}