/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false

*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         stack <char> st;
//         int i;
//         for (i = 0; i < (int) s.size(); i++)
//         {
//             switch (s[i])
//             {
//             case '(':
//                 st.push(')');
//                 break;
//             case '[':
//                 st.push(']');
//                 break;
//             case '{':
//                 st.push('}');
//                 break;
//             case ')':
//             case ']':
//             case '}':
//                 if (!st.empty() && st.top() == s[i])
//                 {
//                     st.pop();
//                 }
//                 else
//                 {
//                     return false;
//                 }
//                 break;
//             default:
//                 break;
//             }
//         }

//         if (st.empty())
//         {
//             return true;
//         }

//         return false;
//     }
// };

//第一种： "([]"
//第二种： "(]"
//第三种： "()]"

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for (auto c:s)
        {
            switch (c)
            {
            case '(':
                st.push(')');
                break;
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            default:
                if (!st.empty() && c == st.top())
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    cout << "{}()[]: " << s.isValid("{}()[]") << endl;
    cout << "({}[]: " << s.isValid("({}[]") << endl;
    cout << "({}[])]: " << s.isValid("({}[])]") << endl;
    cout << "(]{}[]:" << s.isValid("(]{}[]") << endl;
}


// int
// main(int argc, char **agrv)
// {
//     Solution s;
//     string str;

//     str = "()[]{}";
//     cout << s.isValid(str) << endl;


//     str = "()[]{}]";
//     cout << s.isValid(str) << endl;

//     str = "{()[]{}";
//     cout << s.isValid(str) << endl;
//     return 0;
// }