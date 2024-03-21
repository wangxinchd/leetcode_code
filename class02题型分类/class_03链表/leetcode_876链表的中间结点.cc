/*
给你单链表的头结点 head ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。



示例 1：


输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。
示例 2：


输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。


提示：

链表的结点数范围是 [1, 100]
1 <= Node.val <= 100

*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(vector<int> &nums)
{
    int i, len;
    len = (int) nums.size();
    ListNode *tmp_head;

    ListNode *head = new ListNode;
    head->val = nums[0];
    tmp_head = head;

    for (i = 1; i < len; i++)
    {
        ListNode *tmp = new ListNode;
        tmp->val = nums[i];
        tmp_head->next = tmp;
        tmp_head = tmp;
    }

    return head;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ->", head->val);
        head = head->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *first, *secend;
        first = head;
        secend = head;
        while(first != NULL && first->next != NULL)
        {
            first = first->next->next;
            secend = secend->next;
        }

        return secend;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector <int> nums1 = {1,2,3,5,6};
    ListNode *list1 = createList(nums1);

    printList(solution.middleNode(list1));

    return 0;
}