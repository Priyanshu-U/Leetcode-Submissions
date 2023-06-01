/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            Node* ans = new Node(head->val);
            ans->random = head->random?ans:NULL;
            return ans;
        }

        map<Node*,Node*> mapping;

        Node* newList = new Node(head->val);
        Node* ans = newList;

        Node* itr = head;

        mapping[head] = newList; 

        while(itr->next){
            newList->next = new Node(itr->next->val);
            itr=itr->next;
            newList=newList->next;
            mapping[itr]=newList;
        }

        itr = head;
        newList = ans;

        while(itr){
            newList->random = mapping[itr->random];
            newList = newList->next;
            itr = itr->next;
        }

        return ans;

    }
};
