/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]


提示：

1 <= n <= 45

*/

#include <iostream>
#include <vector>
using namespace std;

void
print_vector2(vector<vector<int>> vec)
{
    int i, j, row, col;
    row = (int) vec.size();
    col = (int) vec[0].size();

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d, ", vec[i][j]);
        }
        printf("\n");
    }
    fflush(NULL);
}

class Solution {
public:
/*
i 行
j 列
  ----> x
  |
  |
  y
*/
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        int startx, starty;
        int i, j, offset, count, loop;

        offset = 1;
        startx = starty = 0;
        count = 1;
        i = 0;

        loop = n / 2;  // 循环圈数

        while (loop)
        {
            printf("\n n = %d \n", n);
            for (j = startx; j < n - offset; j++)
            {
                vec[starty][j] =  count++;
            }
            print_vector2(vec);

            for (i = starty; i < n - offset; i++)
            {
                vec[i][j] = count++;
            }
            print_vector2(vec);

            for (; j > startx; j--)
            {
                vec[i][j] = count++;
            }
            print_vector2(vec);

            for (; i > starty; i--)
            {
                vec[i][j] = count++;
            }
            print_vector2(vec);
            offset++;
            startx++;
            starty++;
            loop--;

        }

        if (n % 2)
        {
            vec[n / 2][n / 2] = count;
        }

        return vec;
    }
};

int
main(int argc, char **agrv)
{
    Solution s;
    vector<vector<int>> ret;
    int target;

    ret = s.generateMatrix(3);
    printf("=======1=======\n\n");
    print_vector2(ret);

    printf("=======2=======\n\n");
    ret = s.generateMatrix(1);
    print_vector2(ret);

    printf("=======4=======\n\n");
    ret = s.generateMatrix(4);
    print_vector2(ret);

    return 0;
}
