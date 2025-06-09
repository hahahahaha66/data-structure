#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//方法一
class Solution1 {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* node = head;
            int count = 0;
            while(head != nullptr) {
                count++;
                head = head->next;
            }
            int n = (count / 2) + 1;
            for(int i = 1;i < n;i ++) {
                node = node->next;
            }
            return node;
        }
    };
//方法二
class Solution2 {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    };