#include <algorithm>
class MinStack {
public:
    class Node {
        public:
        long long val;
        long long min;
        Node* next;

        Node (long long val,long long min,Node* next = nullptr) : val(val), min(min), next(next) {}
    };

    Node* head;

public:

    MinStack() {
        head = nullptr;
    }
    
    void push(long long val) {
        if(head == nullptr) {
            head = new Node(val,val);
        }
        else {
            Node* new_node = new Node(val,std::min(val,head->min),head);
            head = new_node;
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }

};