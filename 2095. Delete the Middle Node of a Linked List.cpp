class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;

        ListNode* temp = new ListNode(0);

        ListNode* slow = temp;
        ListNode* fast = temp;

        slow->next = head;
        fast->next = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};
