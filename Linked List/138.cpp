#include <iostream>
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
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }
        Node* temp = head;
        while(head != nullptr) {
            Node* next = head->next;
            head->next = new Node(0);
            head->next->val = head->val;
            head->next->next = next;
            head = next;
        }
        head = temp;
        while(head != nullptr) {
            if(head->random == NULL) {
                head->next->random = NULL;
            }
            else {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        head = temp;
        temp = temp->next;
        Node* result = temp;
        while(head != nullptr) {
           head->next = head->next->next;
           head = head->next;
           if(temp->next != nullptr) {
                temp->next = temp->next->next;
                temp = temp->next;
           }
        }
        return result;
    }
};