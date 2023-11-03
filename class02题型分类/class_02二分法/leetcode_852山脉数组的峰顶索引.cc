/*
题目：
符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] <
arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。



示例 1：

输入：arr = [0,1,0]
输出：1
示例 2：

输入：arr = [0,2,1,0]
输出：1
示例 3：

输入：arr = [0,10,5,2]
输出：1


提示：

3 <= arr.length <= 105
0 <= arr[i] <= 106
题目数据保证 arr 是一个山脉数组


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int
    peakIndexInMountainArray(vector<int> &arr)
    {
        int len = (int) arr.size();
        int right = len - 1, left = 0, mid;

        while (left < right)
        {
            mid = (right + left) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            {
                left = mid;
            }
        }
        return 0;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> arr;

    // 测试1
    arr = { 0, 1, 0 };
    cout << solution.peakIndexInMountainArray(arr) << endl;

    // 测试2
    arr = { 0,2,1,0 };
    cout << solution.peakIndexInMountainArray(arr) << endl;

    // 测试3
    arr = { 0, 10, 5, 2 };
    cout << solution.peakIndexInMountainArray(arr) << endl;

    return 0;
}