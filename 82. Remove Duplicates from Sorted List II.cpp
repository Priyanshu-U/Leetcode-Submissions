class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *iter = head;
        unordered_set<int> dupes;

        while (iter->next != NULL)
        {
            if (iter->val == iter->next->val)
            {
                dupes.insert(iter->val);
            }
            iter = iter->next;
        }

        iter = head; // temp will showcase new head

        while (dupes.find(iter->val) != dupes.end())
        {
            iter = iter->next;
            if (iter == NULL)
            {
                break;
            }
        }
        
        ListNode *cur = iter;

        while (cur != NULL && cur->next != NULL)
        {
            if (dupes.find(cur->next->val) != dupes.end())
            {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }

        return iter;
    }
};
