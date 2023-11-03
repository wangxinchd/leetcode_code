#include <iostream>
#include <queue>

using namespace std;

#if 0
int main()
{
    priority_queue<int> que; // 默认大顶堆
    que.push(7);
    que.push(3);
    que.push(5);
    que.push(4);
    que.push(2);

    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }

    cout << endl;

    return 0;
}
#endif

#if 0
int main()
{
    priority_queue<int, vector<int>, greater<int>> que; // 小顶堆
    que.push(7);
    que.push(3);
    que.push(5);
    que.push(4);
    que.push(2);

    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }

    cout << endl;

    return 0;
}
#endif


struct node
{
    int x;
    int y;

    bool operator < (const node &b) const {
        return this->x < b.x;
    }
};


int main()
{
    priority_queue<node> queue;

    queue.push((node){1, 5});
    queue.push((node){2, 3});
    queue.push((node){9, 4});
    queue.push((node){-5, 5});

    while (!queue.empty())
    {
        cout << queue.top().x << " ";
        queue.pop();
    }
    cout << endl;

    /* 9 2 1 -5 */
    return 0;
}

