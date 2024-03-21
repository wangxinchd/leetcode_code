#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int
    search(vector<int> &nums, int target)
    {
        // write code here
        int left, right, mid;
        left = 0;
        right = ( int )nums.size() - 1;

        if (right == -1) return -1;
        if (nums[left] > target) return -1;
        if (nums[right] < target) return -1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> nums1 = { -1, 1 };
    int ret = solution.search(nums1, 0);
    printf("====%d====\n", ret);

    return 0;
}