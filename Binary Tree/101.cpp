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
//递归
class Solution1 {
public:
    bool compare(TreeNode* left,TreeNode* right) {
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        bool outside = compare(left->left,right->right);
        bool inside = compare(left->right,right->left);
        bool hahaha = outside && inside;
        return hahaha;
    }
    bool isSymmetric(TreeNode* root) {
       if(root == NULL) return true;
       return compare(root->left,root->right);
    }
};
//迭代
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == NULL) {
            return true;
        }
        que.push(root->left);
        que.push(root->right);
        while(!que.empty()) {
            TreeNode* leftnode = que.front();
            que.pop();
            TreeNode* rightnode = que.front();
            que.pop();
            if(leftnode == NULL && rightnode == NULL){
                continue;
            }
            if(!leftnode || !rightnode || !(leftnode->val == rightnode->val)) {
                return false;
            }
            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);
        }
        return true;
    }
};