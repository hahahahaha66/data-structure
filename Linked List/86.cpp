#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) {
            return head;
        }
        ListNode* hahaha = new ListNode(0);
        hahaha->next = head;
        ListNode* lastlower = hahaha;
        ListNode* last = hahaha;
        ListNode* node = head;
        while(node != nullptr) {
            if(node->val < x) {
                if(lastlower->next == node) {
                    lastlower = lastlower->next;
                    last = node;
                    node = node->next;
                }
                else {
                    last->next = node->next;
                    node->next = lastlower->next;
                    lastlower->next = node;
                    node = last->next;
                    lastlower = lastlower->next;
                }
            }
            else {
                last = node;
                node = node->next;
            }
        }
        return hahaha->next;
    }
};