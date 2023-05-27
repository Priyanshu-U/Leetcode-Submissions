class Solution {
    public:
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nex;

        while(cur!=NULL){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};
