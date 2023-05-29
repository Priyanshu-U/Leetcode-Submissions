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
class Solution
{
public:
    ListNode *insertNode(ListNode *head, ListNode *node)
    {
        ListNode *temp = head->next;
        head->next = node;
        node->next = temp;
        return temp;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *nex;

        while (cur != NULL)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    ListNode *findMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head->next->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode *head)
    {

        ListNode *middle = findMiddle(head);

        ListNode *section2 = reverseList(middle->next);

        middle->next = NULL;

        ListNode *iter1 = head;
        ListNode *iter2 = section2;

        while (iter1->next != NULL)
        {
            ListNode *temp1 = iter2->next;
            iter1 = insertNode(iter1, iter2);
            iter2 = temp1;
        }
        iter1->next = iter2;
    }
};
