/*
题目：
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。



示例 1：
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2：
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3：
输入: temperatures = [30,60,90]
输出: [1,1,0]

提示：
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100


*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int>
    dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        int len = ( int )temperatures.size();
        vector<int> ret(len);

        for (int i = 0; i < len; i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        return ret;
    }
};

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

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    print_vector(solution.dailyTemperatures(temperatures));

    temperatures = {30,40,50,60};
    print_vector(solution.dailyTemperatures(temperatures));

    temperatures = {30,60,90};
    print_vector(solution.dailyTemperatures(temperatures));

    return 0;
}