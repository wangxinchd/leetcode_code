/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 

示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
示例 2：

输入：n = 2
输出：false

1 <= n <= 2^31 - 1
*/

#include <iostream>
#include <vector>
#include <unordered_set>


这个题做的有问题，需要再看看

using namespace std;

class Solution {
public:

    int get_new_value(int n)
    {
        int ret;

        ret = (n % 10) * (n % 10);
        while (n > 0)
        {
            if (n > 0 && n <= 9)
            {
                break;
            }

            n = n / 10;
            ret += (n % 10) * (n % 10);
        }

        return ret;
    }

    bool isHappy(int n)
    {
        n = get_new_value(n);
        while (n != 1)
        {
            n = get_new_value(n);

            // if (n > 1 && n <=9) 
            // {
            //     return false;
            // }
        }
        return true;
    }
};


int
main(int argc, char **agrv)
{

    Solution s;
    int num;

    num = 19;
    cout << s.isHappy(num) << endl;

    num = 2;
    cout << s.isHappy(num) << endl;

    num = 1;
    cout << s.isHappy(num) << endl;

    num = 7;
    cout << s.isHappy(num) << endl;

    return 0;
}