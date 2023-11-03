/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
示例 2:

输入: numRows = 1
输出: [[1]]

*/

#include <iostream>
#include <vector>


using namespace std;

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


void
print_vector2(vector<vector<int>> vec)
{
    cout << "打印二维数组\n";
    int i, j, row, col;
    row = (int) vec.size();
    col = (int) vec[0].size();
    printf("===start===\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d, ", vec[i][j]);
        }
        printf("\n");
    }
    printf("===end===\n");
    fflush(NULL);
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> row, last_row;
        int i, j;
        for (i = 0; i < numRows; i++)
        {
            row.resize(i+1);
            for (j = 0; j < (int) row.size(); j++)
            {
                if (j == 0 || j == i)
                {
                    row[j] = 1;
                }
                else
                {
                    row[j] = last_row[j - 1] + last_row[j];
                    // printf("j %d last_row[j-1] : %d + last_row[j]: %d = %d \n",
                    //         j, last_row[j - 1], last_row[j], row[j]);
                }
            }
            last_row = row;
            ret.push_back(row);
        }

        return ret;
    }
};

int
main(int argc, char **agrv)
{
    vector<vector<int>> ret;
    Solution s;
    int numRows;

    ret = s.generate(5);
    // print_vector2(ret);

    return 0;
}