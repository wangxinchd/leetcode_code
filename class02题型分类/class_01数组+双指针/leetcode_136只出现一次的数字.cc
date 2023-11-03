/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 

示例 1 ：

输入：nums = [2,2,1]
输出：1
示例 2 ：

输入：nums = [4,1,2,1,2]
输出：4
示例 3 ：

输入：nums = [1]
输出：1
 

提示：

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
除了某个元素只出现一次以外，其余每个元素均出现两次。
*/

#include <iostream>
#include <vector>
using namespace std;


// 除了某个元素只出现一次以外，其余每个元素均出现两次。 
// 出现两次，采用异或可以有  A ^ A = 0, 所以采用异或可以得到最后唯一出现一次的数。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto num: nums)
        {
            ret ^= num;
        }
        return ret;
    }
};

int
main(int argc, char **agrv)
{
    int ret;
    Solution s;
    vector<int> nums;

    nums = { 2, 2, 1 };
    ret = s.singleNumber(nums);
    cout << ret << endl;
    // print_vector2(ret);

    return 0;
}