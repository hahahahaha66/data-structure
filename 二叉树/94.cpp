#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*>haha;
        TreeNode*node =root;
        while(node||!haha.empty()){
            if(node!=NULL){
                haha.push(node);
                node=node->left;
            }
            else{
                node=haha.top();
                haha.pop();
                result.push_back(node->val);
                node=node->right;
            }
        }
        return result;
    }
};