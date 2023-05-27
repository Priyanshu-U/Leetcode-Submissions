
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                break;
            }
        }

        if(fast==NULL || fast->next==NULL){
            return NULL;
        }

        fast = head;

        while(slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
        }
};
