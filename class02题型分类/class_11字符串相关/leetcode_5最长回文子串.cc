/*
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。


示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
*/

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class Solution {
// public:

//     bool is_match(const string &s)
//     {
//         int i = 0, j = s.length() - 1;

//         while (i < j)
//         {
//             if (s[i] == s[j])
//             {
//                 i++;
//                 j--;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

//     string longestPalindrome(string s) {
//         string ret_s;
//         int i = 0, j = 0, max_len = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             j = s.length() - 1;
//             while (j >= 0)
//             {
//                 if (is_match(s.substr(i, j - i + 1)))
//                 {
//                     if ((j - i + 1) > max_len)
//                     {
//                         max_len = j - i + 1;
//                         ret_s = s.substr(i, max_len);
//                     }
//                 }
//                 j--;
//             }

//         }

//         return ret_s;
//     }
// };

// 动态规划
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string
    longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为 1 的子串都是回文串
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // 递推开始         // 先枚举子串长度
        for (int L = 2; L <= n; L++)
        {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++)
            {
                // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
                int j = L + i - 1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i < 3)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
                // 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    string s = "babad";

    string res;
    // res = solution.longestPalindrome(s);
    // printf("res: %s \n", res.c_str());

    // s = "cbbd";
    // res = solution.longestPalindrome(s);
    // printf("res: %s \n", res.c_str());

    // s = "a";
    // res = solution.longestPalindrome(s);
    // printf("res: %s \n", res.c_str());

    // s =
    // "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
    //     "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    // res = solution.longestPalindrome(s);

    s = "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababababababababababababababababababababa"
        "babababababababababababababababababababababababababababababababababab"
        "ababababababababababababababababa";
    res = solution.longestPalindrome(s);

    printf("res: %s \n", res.c_str());
    return 0;
}