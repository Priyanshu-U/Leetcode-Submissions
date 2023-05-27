class Solution
{
public:
    int size(ListNode *head)
    {
        int ctr = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            ctr++;
        }
        return ctr;
    }
    ListNode *reverseK(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        if (size(head) < k)
        {
            return head;
        }

        int tempK = k;

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *nex;
        while (tempK--)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        head->next = reverseK(cur, k);
        return pre;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return reverseK(head, k);
    }
};
