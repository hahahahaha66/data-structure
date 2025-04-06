/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode*now=head;
    struct ListNode*last=head;
    while(now!=NULL){
        if(now->val==val){
            if(now==head){
                head=head->next;
                free(now);
                now=head;;
            }
            else{
                last->next=now->next;
                free(now);
                now=last->next;
            }
        }
        else{
            last=now;
            now=now->next;
        }
    }
    return head;
}