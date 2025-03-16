#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        que.push(root);
        while(!que.empty()){
            vector<int> temp;
            int size=que.size();
            for(int i=0;i<size;i++){
                Node* node=que.front();
                que.pop();
                temp.push_back(node->val);
                for(Node* a : node->children){
                    if(a){
                        que.push(a);
                    }
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};