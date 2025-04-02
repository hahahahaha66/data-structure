#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution1 {
public:
    void haha(TreeNode*root,vector<int>*a){
        if(root==NULL){
            return ;
        }
        int temp=root->val;
        a->push_back(temp);
        haha(root->left,a);
        haha(root->right,a);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ha;
        haha(root,&ha);
        return ha;
    }
};
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>haha;
        stack<TreeNode*>ha;
        if(root==NULL){
            return haha;
        }
        ha.push(root);
        while(!ha.empty()){
            TreeNode*node=ha.top();
            ha.pop();
            haha.push_back(node->val);
            if(node->right!=NULL){
                ha.push(node->right);
            }
            if(node->left!=NULL){
                ha.push(node->left);
            }
        }
        return haha;
    }
};