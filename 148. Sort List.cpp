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
    ListNode* findMiddle(ListNode* head){
        if(head==NULL || head->next ==NULL){
            return head;
        }

        ListNode* iter= head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;

            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* mergedList= new ListNode(-1);
        ListNode* ans = mergedList;

        if(l1==NULL){
            return l2;
        }
        else if (l2==NULL){
            return l1;
        }

        ListNode* list1 = l1;
        ListNode* list2 = l2;


        while(list2&&list1){
            if(list1->val <= list2->val){
                mergedList->next = list1;
                list1 = list1->next;
                mergedList = mergedList->next;
            }
            else{
                mergedList->next = list2;
                list2 = list2->next;
                mergedList = mergedList->next;
            }
        }
        if(list1){
            mergedList->next = list1;
        }
        else if(list2){
            mergedList->next = list2;
        }

        return ans->next;

    }

    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* left = head;

        return mergeList(sortList(left),sortList(right));
    }
};
