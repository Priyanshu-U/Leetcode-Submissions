Node *removeDuplicates(Node *head)
{
    if (head == NULL) return NULL;

    unordered_set<int> count;
    Node* temp = head;
    count.insert(head->data);

    while(temp->next != NULL){
        if (count.find(temp->next->data) == count.end()) {
            count.insert(temp->next->data);
            temp=temp->next;
        } else {
            Node *holder = temp->next;
            temp->next = holder->next;
            delete holder;
        }
    }
    return head;
}
