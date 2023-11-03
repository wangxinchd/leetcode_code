/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 
给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1：

输入：nums = [3,2,3]
输出：3
示例 2：

输入：nums = [2,2,1,1,1,2,2]
输出：2

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void
print_umap(unordered_map <int, int> map1)
{
    for (auto it : map1)
    {
        cout << it.first << ":" << it.second << endl;
    }
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = (int) nums.size();
        unordered_map <int, int> umap;

        if (len == 1)
        {
            return nums[0];
        }

        for (int i = 0; i < len; i++)
        {
            print_umap(umap);

            if (umap.find(nums[i]) != umap.end())
            {
                umap.at(nums[i])++;

                if (umap.at(nums[i]) > len / 2)
                {
                    return nums[i];
                }
            }
            else
            {
                umap.emplace(nums[i], 1);
            }
        }


        return 0;
    }
};


int
main(int argc, char **agrv)
{

    Solution s;
    vector<int> nums;

    // nums = { 3, 2, 3 };
    // cout << s.majorityElement(nums) << endl;

    // nums = { 2, 2, 1, 1, 1, 2, 2 };
    // cout << s.majorityElement(nums) << endl;

    nums = { 6, 5, 5 };
    cout << s.majorityElement(nums) << endl;

    return 0;
}