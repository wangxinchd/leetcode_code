

#include <iostream>
#include <vector>

using namespace std;

// struct ListNode
// {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
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

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *
    ReverseList(ListNode *head)
    {
        // write code here
        ListNode *curr = head, *pre = nullptr;
        ListNode *tmp;

        while (curr != nullptr)
        {
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }

        return pre;
    }
};

int
main(int argc, char **agrv)
{
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    ListNode *list1 = createList(nums1);
    printList(list1);

    ListNode *ret = solution.ReverseList(list1);

    printList(ret);

    return 0;
}