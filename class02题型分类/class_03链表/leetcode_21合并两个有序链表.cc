/*
21. 合并两个有序链表
简单
3.3K
相关企业
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(-1);
        ListNode *p = &dummyHead;
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }

        if (p1 != NULL)
        {
            p->next = p1;
        }

        if (p2 != NULL)
        {
            p->next = p2;
        }
        return dummyHead.next;
    }

};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector <int> nums1 = {1,2,4};
    vector <int> nums2 = {1,3,4};
    ListNode *list1 = createList(nums1);
    printList(list1);
    ListNode *list2 = createList(nums2);
    printList(list2);

    printList(solution.mergeTwoLists(list1, list2));

    return 0;
}