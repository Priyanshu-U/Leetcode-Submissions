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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return head;
        }

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* temp;

        while(cur!=NULL){
            if(pre->val==cur->val){
                temp = cur -> next;
                cur = temp;
                pre->next = cur;
            }
            else{
                pre = cur;
                cur = cur ->next;
            }
        }
        return head;
    }
};
