/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"
示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 104
s 仅由小写英文组成
1 <= k <= 104
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse_str_from_start_to_end(string &s, int start, int end)  // 将字符串从 开始到结束前一个位置，进行反转。
    {
        int i, left, right;
        left = start;
        right = end - 1;
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        int i, size;
        int end;
        size = s.length();

        for (i = 0; i < size - 1; i += 2 * k)
        {
            if (i + k > size - 1)  // 如果剩余字符少于 k 个，则将剩余字符全部反转。
            {
                end = size; // 此时结束位置不同
            }
            else
            {
                end = i + k;
            }
            reverse_str_from_start_to_end(s, i, end);
        }
        return s;
    }
};

int
main(int argc, char **agrv)
{
    int k;
    Solution solution;
    string s, ret;

    // s = "abcdefg";  // bacdfeg
    // solution.reverse_str_from_start_to_end(s, 1, 5);
    // cout << s << endl;

    printf("==========\n");
    s = "abcdefg";  // bacdfeg
    k = 2;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;

    printf("==========\n");
    s = "abcdefg";  // cbadefg
    k = 3;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;

    printf("==========\n");
    s = "abcd";   //bacd
    k = 2;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;

    printf("==========\n");
    s = "abcdef";   // cbadef
    k = 3;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;

    printf("==========\n");
    s = "abcdef";   // cbadef
    k = 4;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;

    printf("==========\n");
    s = "abcdefg";   // gfedcba
    k = 8;
    ret = solution.reverseStr(s, k);
    cout << ret << endl;
    

    return 0;
}