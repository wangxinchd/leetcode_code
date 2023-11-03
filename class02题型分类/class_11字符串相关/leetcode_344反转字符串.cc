/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

 

示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
 

提示：

1 <= s.length <= 105
s[i] 都是 ASCII 码表中的可打印字符
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int len = (int) s.size();

        for (int i = 0; i < len / 2; i++)
        {
            tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }

        for (int i = 0; i < len; i++)
        {
            cout << s[i] << endl;
        }
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<char> s;

    s = {'h','e','l','l','o'};
    solution.reverseString(s);

    return 0;
}