/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
 

提示：

m == s.length
n == t.length
1 <= m, n <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？


*/
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

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

class Solution {
public:
    unordered_map <char, int> substr_umap;

    bool is_substr(const string &str)
    {
        unordered_map <char, int> umap;

        for (auto s:str)
        {
            if (umap.find(s) == umap.end())
            {
                umap.emplace(s, 1);
            }
            else
            {
                umap.at(s)++;
            }
        }

        for (auto it:substr_umap)
        {
            if (umap.find(it.first) == umap.end() || it.second > umap[it.first])
            {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {
        for (auto t_sub : t)
        {
            if (substr_umap.find(t_sub) == substr_umap.end())
            {
                substr_umap.emplace(t_sub, 1);
            }
            else
            {
                substr_umap.at(t_sub)++;
            }
        }

        string substr;

        int fast, slow;
        fast = slow = 0;

        int right, len;
        right = 0;
        len = INT32_MAX;

        while (fast < (int) s.length())
        {
            fast++;
            if (fast - slow < t.length())
            {
                continue;
            }
            substr = s.substr(slow, fast - slow);

            // printf("substr: %s \n", substr.c_str());
            if (is_substr(substr))
            {
                // printf("is substr \n");

                if (len > substr.length())
                {
                    right = slow;
                    len = fast - slow;
                }

                while (true)
                {
                    slow++;
                    if (slow >= fast) break;

                    substr = s.substr(slow, fast - slow);
                    if (is_substr(substr))
                    {
                        if (len > substr.length())
                        {
                            right = slow;
                            len = fast - slow;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if (len != INT32_MAX)
        {
            return s.substr(right, len);
        }
        else
        {
            return "";
        }
    }
};



int
main(int argc, char **agrv)
{
    Solution solution;
    printf("======1======\n");
    string s = "ADOBECODEBANC";
    string t = "ABC";


    cout << solution.minWindow(s, t) << endl;
    // cout << solution.is_substr("A") << endl;


    // printf("======2======\n");
    // s = "a";
    // t = "a";
    // cout << solution.minWindow(s, t) << endl;

    // printf("======3======\n");
    // s = "a";
    // t = "aa";
    // cout << solution.minWindow(s, t) << endl;

    printf("======4======\n");


    return 0;
}