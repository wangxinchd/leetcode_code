/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <unordered_set>

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

/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        vector<int> ret(0);
        unordered_set<int> ret_set;
        unordered_set<int> temp_set;

        for (i = 0; i < (int) nums1.size(); i++)
        {
            ret_set.insert(nums1[i]);
        }

        for (i = 0; i < (int) nums2.size(); i++)
        {
            if (ret_set.find(nums2[i]) != ret_set.end())
            {
                temp_set.insert(nums2[i]);
            }
        }

        // for (unordered_set<int>::iterator it = temp_set.begin();
        //         it != temp_set.end(); it++)
        // {
        //     ret.push_back(*it);
        // }
        ret = vector<int>(temp_set.begin(), temp_set.end());

        return ret;
    }
};
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        vector<int> ret(0);
        int hash[1000] = {0};

        for (i = 0; i < (int) nums1.size(); i++)
        {
            hash[nums1[i]] = 1;
        }

        for (i = 0; i < (int) nums2.size(); i++)
        {
            if (hash[nums2[i]] == 1)
            {
                hash[nums2[i]] = 2;
            }
        }

        for (i = 0; i < 1000; i++)
        {
            if (hash[i] == 2)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};

/**/

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> ret;
    vector<int> nums1;
    vector<int> nums2;

    nums1 = {1,2,2,1};
    nums2 = {2,2};
    ret =  solution.intersection(nums1, nums2);
    print_vector(ret);

    nums1 = {4,9,5};
    nums2 = {9,4,9,8,4};
    ret =  solution.intersection(nums1, nums2);
    print_vector(ret);

    return 0;
}