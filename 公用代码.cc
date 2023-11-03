
// 打印数组
void print(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", *(p+i));
    }
    printf("\n");
}

// 打印vector
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

// 打印二维vector
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

void
print_umap(unordered_map <int, int> map1)
{
    for (auto it : map1)
    {
        cout << it.first << ":" << it.second << endl;
    }
}
