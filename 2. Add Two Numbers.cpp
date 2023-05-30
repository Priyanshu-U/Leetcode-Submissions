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
class Solution {
public:
    int sizeOf(ListNode* head){
        int ctr = 0;
        while(head){
            ctr++;
            head = head->next;
        }
        return ctr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* rl1;
    ListNode* rl2;
    
    if(sizeOf(l1) < sizeOf(l2)){
        rl1 = l2;
        rl2 = l1;
    }
    else{
        rl1 = l1;
        rl2 = l2;
    }

    ListNode* ans = rl1;
    ListNode* prev = nullptr;
    int carry = 0;

    while(rl1 || carry){
        int total = (rl1 ? rl1->val : 0) + (rl2 ? rl2->val : 0) + carry;
        carry = total / 10;
        
        if (rl1) {
            rl1->val = total % 10;
            prev = rl1;
            rl1 = rl1->next;
        }
        else if (prev) {
            prev->next = new ListNode(total % 10);
            prev = prev->next;
        }
        
        if (rl2) {
            rl2 = rl2->next;
        }
    }
    

    return ans;
}

};
