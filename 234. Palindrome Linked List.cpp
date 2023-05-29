
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nex;

        while(cur){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur=nex;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle = findMiddle(head);

        ListNode* section2 = reverseList(middle->next);

        middle->next = NULL;

        ListNode* iter1 = head;
        ListNode* iter2 = section2;

        while(iter1!=NULL && iter2!=NULL){
            if(iter1->val != iter2->val){
                return false;
            }
            iter1=iter1->next;
            iter2=iter2->next;
        }

        section2=reverseList(section2);

        middle->next = section2;

        return true;
    }
};
