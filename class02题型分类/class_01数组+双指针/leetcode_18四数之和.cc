/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]


*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void
print_vector2(vector<vector<int>> vec)
{
    int i, j, row, col;
    row = (int) vec.size();
    col = (int) vec[0].size();

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d, ", vec[i][j]);
        }
        printf("\n");
    }
    fflush(NULL);
}
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int i, j, left, right;
        long long sum;
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (i = 0; i < len - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i -1]) continue;
            for (j = i + 1; j < len; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                left = j + 1;
                right = len - 1;
                while (left < right)
                {
                    printf("(%d, %d, %d, %d) => (%d, %d, %d, %d)\n", i, j,
                            left, right, nums[i], nums[j], nums[left],
                            nums[right]);
                    sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ret.push_back(
                                { nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) // 如果发现当前的左指针数值等于右指针数值进行剪枝
                        {
                            left++;
                        }
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
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
    vector<int> nums;
    vector<vector<int>> ret;

    // 测试01  2
    // nums = { -1, -1, 2};
    // ret = s.threeSum(nums);
    // printf("**********\n"); 
    // print_vector2(ret);

    // // 测试01  2
    // printf("=====\n");
    // nums = { 0, 0, 0 };
    // ret = s.threeSum(nums);
    // printf("**********\n"); 
    // print_vector2(ret);

    // nums =  {-1,0,1,2,-1,-4};
    // ret = s.threeSum(nums);
    // printf("**********\n");
    // print_vector2(ret);

    // printf("=====\n");
    // nums = { 1,0,-1,0,-2,2 };
    // ret = s.fourSum(nums, 0);
    // printf("**********\n");
    // print_vector2(ret);

    // printf("=====\n");
    // nums = { 2,2,2,2,2 };
    // ret = s.fourSum(nums, 8);
    // printf("**********\n");
    // print_vector2(ret);

    printf("=====\n");
    nums = { 1000000000, 1000000000, 1000000000, 1000000000 };
    ret = s.fourSum(nums, 0);
    printf("**********\n");
    print_vector2(ret);
}