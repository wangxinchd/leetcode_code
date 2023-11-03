/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

示例 1：

输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
示例 2：

输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
 

  提示：

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int i, j, m, n, sum, result;
        unordered_map<int, int> umap12, umap34;

        result = 0;
        for (i = 0; i < (int) nums1.size(); i++)
        {
            for (j = 0; j < (int) nums2.size(); j++)
            {
                sum = nums1[i] + nums2[j];

                if (umap12.find(sum) == umap12.end())
                {
                    umap12.emplace(sum, 1);
                }
                else
                {
                    umap12.at(sum)++;
                }
            }
        }

        for (i = 0; i < ( int )nums3.size(); i++)
        {
            for (j = 0; j < (int) nums4.size(); j++)
            {
                sum = nums3[i] + nums4[j];
                if (umap34.find(sum) == umap34.end())
                {
                    umap34.emplace(sum, 1);
                }
                else
                {
                    umap34.at(sum)++;
                }
            }
        }

        for (auto iter = umap12.begin(); iter != umap12.end(); ++iter)
        {
            if (umap34.find(0 - iter->first) != umap34.end())
            {
                result += iter->second * umap34.at(0 - iter->first);
            }
        }

        return result;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    int target;
    vector<int> nums1, nums2, nums3, nums4;

    // 测试01  2
    nums1 = { 1, 2 };
    nums2 = { -2, -1 };
    nums3 = { -1, 2 };
    nums4 = { 0, 2 };
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    nums1 = { 0 };
    nums2 = { 0 };
    nums3 = { 0 };
    nums4 = { 0 };

    // 测试02  1
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;

    // 测试03  6
    nums1 = { -1, -1 };
    nums2 = { -1, 1 };
    nums3 = { -1, 1 };
    nums4 = { 1, -1 };
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
}