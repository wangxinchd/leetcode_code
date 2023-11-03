/*
题目：
全字母句 指包含英语字母表中每个字母至少一次的句子。

给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。

如果是，返回 true ；否则，返回 false 。

 

示例 1：

输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
输出：true
解释：sentence 包含英语字母表中每个字母至少一次。
示例 2：

输入：sentence = "leetcode"
输出：false


提示：

1 <= sentence.length <= 1000
sentence 由小写英语字母组成
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool
    checkIfPangram(string sentence)
    {
        int hash[26];

        for (int i = 0; i < 26; i++)
        {
            hash[i] = 0;
        }

        for (int i = 0; i < sentence.length(); i++)
        {
            hash[sentence[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (hash[i] == 0) return false;
        }

        return true;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    string s;

    s = "jwtucoucmdfwxxqnxzkaxoglszmfrcvjoiunqqausaxxaaijyqdqgvdnqcaihwilqkpivenpnekioyqujrdrovqrlxovcucjqzjsxmllfgndfprctxvxwlzjtciqxgsxfwhmuzqvlksyuztoetyjugmswfjtawwaqmwyxmvo";
    cout << solution.checkIfPangram(s) << endl;

    return 0;
}