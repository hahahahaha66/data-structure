#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root==NULL){
            return root;
        }
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            Node* last=NULL;
            Node* node=NULL;
            for(int i=0;i<size;i++){
                node=que.front();
                if(last){
                    last->next=node;
                }
                last=que.front();
                que.pop();
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            node->next=NULL;
        }
        return root;
    }
};