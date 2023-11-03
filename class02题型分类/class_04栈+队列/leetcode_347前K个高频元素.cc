/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。


示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]


提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的


进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。


*/
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void
print_umap(unordered_map <int, int> map1)
{
    for (auto it : map1)
    {
        cout << it.first << ":" << it.second << endl;
    }
}


void
print_vector(vector<int> v)
{
    cout << "打印一维数组\n";
    cout << "[";
    for (int i = 0; i < (int) v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    struct cmp
    {
        bool
        operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        for (auto n: nums)
        {
            if (umap.find(n) != umap.end())
            {
                umap.at(n) ++;
            }
            else
            {
                umap.emplace(n, 0);
            }
        }
        print_umap(umap);

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;  // 采用优先队列

        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
        {
            que.push(*it);
            if (que.size() > k)
            {
                que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = que.top().first;
            que.pop();
        }

        return result;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    vector <int> nums = {1,1,1,2,2,3};

    vector <int> ret = s.topKFrequent(nums, 2);
    print_vector(ret);
    return 0;
}