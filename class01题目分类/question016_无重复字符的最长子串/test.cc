/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

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
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
class Solution
{
public:
    int
    lengthOfLongestSubstring(std::string s)
    {
        int max_length = 0;
        std::cout << s.size() << std::endl;

        for (int i = 0; i < s.size(); i++)
        {
            int tmp_size = 0;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    break;
                }
                else
                {
                    tmp_size++;
                }

                if (tmp_size > max_length)
                {
                    max_length = tmp_size;
                    std::cout << "此时" << max_length << std::endl;
                    std::cout << "s[" << i << "] = " << s[i] << std::endl;
                    std::cout << "s[" << j << "] = " << s[jt] << std::endl;
                }
            }
        }

        return max_length;
    }
};

int
main()
{
    Solution s;
    std::cout << "abcabcbb输出: " << s.lengthOfLongestSubstring("abcabcbb")
              << std::endl;

    return 0;
}