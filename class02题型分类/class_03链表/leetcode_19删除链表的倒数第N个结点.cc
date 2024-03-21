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

#if 0
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0, len = 0;
        ListNode *p = head;
        ListNode *tmp;

        while (p != NULL)
        {
            len++;
            p = p->next;
        }

        ListNode dummyHead(-1);
        dummyHead.next = head;

        p = &dummyHead;
        for (i = 0; i < len - n; i++)
        {
            // printList(p);
            p = p->next;
        }
        tmp = p->next;
        p->next = p->next->next;
        delete tmp;

        return dummyHead.next;
    }
};
#endif

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i;
        ListNode dummyHead(-1);
        ListNode *first, *secend;

        dummyHead.next = head;
        first = &dummyHead;
        secend = &dummyHead;

        for (i = 0; i < n + 1; i++)
        {
            first = first->next;
        }

        while (first != NULL)
        {
            first = first->next;
            secend = secend->next;
        }
        secend->next = secend->next->next;

        return dummyHead.next;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    ListNode *list1 = createList(nums1);
    // printList(list1);

    ListNode *ret = solution.removeNthFromEnd(list1, 2);

    printList(ret);

    printf("====2====\n");
    vector<int> nums2 = { 1 };
    ListNode *list2 = createList(nums2);
    ret = solution.removeNthFromEnd(list2, 1);
    printList(ret);

    return 0;
}