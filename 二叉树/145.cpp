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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>arr;
        if(root==NULL){
            return result;
        }
        arr.push(root);
        while(!arr.empty()){
            TreeNode*node=arr.top();
            arr.pop();
            result.push_back(node->val);
            if(node->left) arr.push(node->left);
            if(node->right) arr.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
};