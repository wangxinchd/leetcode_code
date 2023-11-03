/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, left, right, len, sum;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        print_vector(nums);

        len = (int) nums.size();

        for (i = 0; i < len; i++)
        {
            left = i + 1;
            right = len - 1;

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            while(left < right)
            {
                printf("(%d, %d, %d)\n", i, left, right);
                sum = nums[i] + nums[left] + nums[right];
                printf("nums[%d] = %d, nums[%d] = %d, nums[%d] = %d\n", i,
                        nums[i], left, nums[left], right, nums[right]);

                if (sum == 0)
                {
                    ret.push_back(vector<int>{ nums[i], nums[left], nums[right]});
                    left++;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        printf("============\n");
                        left++;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
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
    printf("=====\n");
    nums = { 0, 0, 0 };
    ret = s.threeSum(nums);
    printf("**********\n"); 
    print_vector2(ret);

    // nums =  {-1,0,1,2,-1,-4};
    // ret = s.threeSum(nums);
    // printf("**********\n");
    // print_vector2(ret);

    // nums = { -1, 0, 1, 2, -1, -4 };
    // ret = s.threeSum(nums);
    // printf("**********\n");
    // print_vector2(ret);
}