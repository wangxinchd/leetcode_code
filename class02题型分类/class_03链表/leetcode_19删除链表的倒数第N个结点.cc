/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

进阶：你能尝试使用一趟扫描实现吗？


*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(int n)
{
    int i;
    ListNode *tmp_head;

    ListNode *head = new ListNode;
    tmp_head = head;

    for (i = 0; i < n; i++)
    {
        ListNode *tmp = new ListNode;
        tmp_head->next = tmp;
        tmp_head = tmp;
    }

    return head;
}

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0, len = 0;
        ListNode dummyHead(-1);
        dummyHead.next = head;

        ListNode *p = head;

        while (p != NULL)
        {
            len++;
            p = p->next;
        }

        p = head;
        while (p != NULL)
        {
            i++;
            if (i == len - n)
            {
                p = p->next->next;
            }
            p = p->next;
        }

        cout << "len: " << len << endl;

        return dummyHead.next;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    ListNode *list1 = createList(nums1);
    printList(list1);

    printList(solution.removeNthFromEnd(list1, 2));

    return 0;
}