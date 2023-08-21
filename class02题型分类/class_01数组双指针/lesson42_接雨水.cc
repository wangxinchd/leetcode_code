/*
题目：
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int
    trap(vector<int> &height)
    {
        int i, j, max_water, max_left_height, max_right_height;
        int len = ( int )height.size();

        i = 0;
        j = len - 1;
        max_water = max_left_height = max_right_height = 0;
        while (i < j)
        {
            max_left_height = max(height[i], max_left_height);
            max_right_height = max(height[j], max_right_height);
            if (height[i] < height[j])
            {
                max_water += max_left_height - height[i];
                i++;
            }
            else
            {
                max_water += max_right_height - height[j];
                j--;
            }
        }
        return max_water;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    int target;
    vector<int> height;

    // 测试01
    height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << s.trap(height) << endl;

    // 测试02
    height = {4,2,0,3,2,5};
    cout << s.trap(height) << endl;

    // 测试03
    height = {4,2,3};
    cout << s.trap(height) << endl;

}