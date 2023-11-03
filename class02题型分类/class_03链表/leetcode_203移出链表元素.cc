/*
题目：
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，
并返回 新的头节点 。

示例 1：


输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]
 

提示：

列表中的节点数目在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= val <= 50


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


class Solution
{
public:
    ListNode *
    removeElements(ListNode *head, int val)
    {
        ListNode *cur, *tmp;
        ListNode dummyHead(-1, head);

        cur = &dummyHead;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        head = dummyHead.next;

        return head;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector <int> nums = {1,2,6,3,4,5,6};
    ListNode *head = createList(nums);
    printList(head);

    solution.removeElements(head, 6);
    printList(head);

    return 0;
}