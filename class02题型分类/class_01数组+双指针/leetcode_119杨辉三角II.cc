/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:

输入: rowIndex = 3
输出: [1,3,3,1]
示例 2:

输入: rowIndex = 0
输出: [1]
示例 3:

输入: rowIndex = 1
输出: [1,1]


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
    vector<int> getRow(int rowIndex) {
        vector<int> row, last_row;
        int i, j;
        for (i = 0; i <= rowIndex; i++)
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
        }

        return row;
    }
};

int
main(int argc, char **agrv)
{
    vector<int> ret;
    Solution s;
    int numRows;

    ret = s.getRow(3);
    print_vector(ret);

    return 0;
}