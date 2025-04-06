//循环
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*now=NULL;
    struct ListNode*last=head;
    struct ListNode*temp=NULL;
    while(last!=NULL){
        temp=last->next;
        last->next=now;
        now=last;
        last=temp;
    }
    return now;
}
//递归
struct ListNode* haha(struct ListNode*now,struct ListNode*last){
    if(last==NULL){
        return now;
    }
    struct ListNode*temp=last->next;
    last->next=now;
    now=last;
    last=temp;
    return haha(now,last);
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode*now=NULL;
    struct ListNode*last=head;
    return haha(now,last);
}