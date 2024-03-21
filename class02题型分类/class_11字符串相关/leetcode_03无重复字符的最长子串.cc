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
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int
    lengthOfLongestSubstring(string s)
    {
        int i, j, len = s.length();
        int max_len_sub = 0;
        unordered_set <char> uset;

        printf("len : %d \n", len);

        if (len > 0)
        {
            max_len_sub = 1;
        }

        for (i = 0; i < len; i++)
        {
            j = i;
            while (j < len)
            {
                if (uset.find(s[j]) == uset.end())
                {
                    uset.insert(s[j]);
                }
                else
                {
                    if (max_len_sub < uset.size())
                    {
                        max_len_sub = uset.size();
                    }
                    uset.clear();
                    break;
                }
                j++;
            }
        }

        return max_len_sub;
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

    s = " ";
    cout << solution.lengthOfLongestSubstring(s) << endl;

    s = "jbpnbwwd";
    cout << solution.lengthOfLongestSubstring(s) << endl;

}