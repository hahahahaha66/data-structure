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
class Solution1 {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if(root == NULL) {
            return 0;
        }
        que.push(root);
        int depth = 0;
        while(!que.empty()) {
            int size = que.size();
            depth++;
            for(int i = 0;i < size;i++) {
                Node* node = que.front();
                que.pop();

                for(auto& i : node->children) {
                    if(i != NULL) que.push(i);
                }
            }
        }
        return depth;
    }
};
class Solution2 {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        for(int i = 0;i < root->children.size();i++) {
            depth = max(depth,maxDepth(root->children[i]));
        }
        return depth+1;
    }
};