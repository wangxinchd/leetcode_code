/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


*/

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void print(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", *(p+i));
    }
    printf("\n");
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        int i, len;

        len = (int) s.length();
        for (i = 0; i < len; i++)
        {
            hash[s[i] - 'a']++;
        }
        print(hash, 26);

        len = ( int )t.length();
        for (i = 0; i < len; i++)
        {
            hash[t[i] - 'a']--;
        }
        print(hash, 26);

        for (i = 0; i < 26; i++)
        {
            if (hash[i] != 0) return false;
        }
        return true;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    string s, t;

    s = "anagram";
    t = "nagaram";

    cout << solution.isAnagram(s, t) << endl;

    s = "rat";
    t = "car";
    cout << solution.isAnagram(s, t) << endl;
}