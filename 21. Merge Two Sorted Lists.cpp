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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }

        ListNode *newList;

        ListNode *iter1 = list1;
        ListNode *iter2 = list2;

        if (iter1->val < iter2->val)
        {
            newList = iter1;
            iter1 = iter1->next;
        }
        else
        {
            newList = iter2;
            iter2 = iter2->next;
        }

        ListNode *ans = newList;

        while (iter1 != NULL && iter2 != NULL)
        {
            if (iter1->val >= iter2->val)
            {
                newList->next = iter2;
                newList = newList->next;
                iter2 = iter2->next;
            }
            else
            {
                newList->next = iter1;
                newList = newList->next;
                iter1 = iter1->next;
            }
        }

        if (iter1 == NULL)
        {
            newList->next = iter2;
        }
        else
        {
            newList->next = iter1;
        }

        return ans;
    }
};
