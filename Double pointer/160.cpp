#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* nodea = headA;
            ListNode* nodeb = headB;
            int a = 0;
            int b = 0;
            while(nodea != nullptr) {
                a++;
                nodea = nodea->next;
            }
            while(nodeb != nullptr) {
                b++;
                nodeb = nodeb->next;
            }
            ListNode* longnode = nullptr;
            ListNode* shortnode = nullptr;
            int n = a - b;
            if(n < 0) {
                n = -n;
                shortnode = headA;
                longnode = headB;
            }
            else {
                longnode = headA;
                shortnode = headB;
            }
            for(int i = 0;i < n;i ++) {
                longnode = longnode->next;
            }
            while(longnode != nullptr && shortnode != nullptr) {
                if(longnode == shortnode) {
                    return longnode;
                }
                longnode = longnode->next;
                shortnode = shortnode->next;
            }
            return nullptr;
        }
    };
//优雅的代码
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* p = headA;
            ListNode* q = headB;
            while (p != q) {
                p = p ? p->next : headB;
                q = q ? q->next : headA;
            }
            return p;
        }
    };