struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len1=0;
    int len2=0;
    struct ListNode*temp1=headA;
    struct ListNode*temp2=headB;
    while(temp1){
        temp1=temp1->next;
        len1++;
    }
    while(temp2){
        temp2=temp2->next;
        len2++;
    }
    temp1=headA;
    temp2=headB;
    if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            temp1=temp1->next;
        }
    }
    else if(len2>len1){
        for(int i=0;i<len2-len1;i++){
            temp2=temp2->next;
        }
    }
    while(temp1&&temp2){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL;
}
