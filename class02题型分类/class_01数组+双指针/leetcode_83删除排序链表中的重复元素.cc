/*
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。


示例 1：


输入：head = [1,1,2]
输出：[1,2]
示例 2：


输入：head = [1,1,2,3,3]
输出：[1,2,3]
 

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;

        if (head == NULL) return head;

        while (fast != NULL)
        {
            if (fast->val != slow->val)
            {
                 slow->next = fast;
                 slow = slow->next;
            }
            fast = fast->next;
        }

        slow->next = NULL;

        return head;
    }
};