struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ehead;
    ehead.next=head;
    struct ListNode*temp=&ehead;
    while(temp->next!=NULL&&temp->next->next!=NULL){
        struct ListNode*first=temp->next;
        struct ListNode*second=temp->next->next;
        temp->next=second;
        first->next=second->next;
        second->next=first;
        temp=first;
    }
    return ehead.next;
}