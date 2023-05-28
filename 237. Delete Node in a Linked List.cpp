class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next->next==NULL){
            node->val = node->next->val;
            node->next = NULL;
            return;
        }
        
        ListNode* temp = node;
        while(temp->next->next!=NULL){
            temp->val = temp->next->val;
            temp=temp->next;
        }
        temp->val=temp->next->val;
        temp->next = NULL;
    }
};
