#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool compare(TreeNode*left,TreeNode*right) {
        if(left == NULL && right !=NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        bool leftside = compare(left->left,right->left);
        bool rightside = compare(left->right,right->right);
        bool hahaha = leftside && rightside;
        return hahaha;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        if(root != NULL) {
            que.push(root);
        }
        while(!que.empty()) {
            int size = que.size();
            for(int i=0;i<size;i++) {
                TreeNode* node = que.front();
                que.pop();
                if(compare(node,subRoot) == true) {
                    return true;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return false;
    }
};