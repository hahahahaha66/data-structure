struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ehead;
    ehead.next=head;
    struct ListNode*temp=&ehead;
    while(temp->next!=NULL){
        struct ListNode*temmp=temp->next;
        for(int i=0;i<n;i++){
            temmp=temmp->next;
        }
        if(temmp==NULL){
            temmp=temp->next;
            temp->next=temmp->next;
            break;
        }
        temp=temp->next;
    }
   return ehead.next;
}