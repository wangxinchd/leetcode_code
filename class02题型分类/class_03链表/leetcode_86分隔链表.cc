/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

 

示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]
 


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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyHead1(-1), dummyHead2(-1);

        dummyHead1.next = head;
        dummyHead2.next = head;

        ListNode *p = head;
        ListNode *p1 = &dummyHead1; // >=
        ListNode *p2 = &dummyHead2; // <

        while (p != NULL)
        {
            if (p->val >= x)
            {
                p1->next = p;
                p1 = p1->next;
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = NULL;
        // printList(dummyHead1.next);
        // printList(dummyHead2.next);
        p2->next = dummyHead1.next;

        return dummyHead2.next;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> nums1 = {1,4,3,2,5,2};
    ListNode *list1 = createList(nums1);

    printList(solution.partition(list1, 3));

    return 0;
}