/*
题目：
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。


示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int
    lengthOfLongestSubstring(string s)
    {
        int max_len = 1;
        int len = ( int ) s.length();

        for (int i = 0; i < len - 1; i++)
        {
            int one_len = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] != s[j])
                {
                    one_len++;
                }
                else
                {
                    break;
                }
            }
            if (one_len > max_len)
            {
                max_len = one_len;
            }
        }
        return max_len;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    string s;

    s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << solution.lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << solution.lengthOfLongestSubstring(s) << endl;
}