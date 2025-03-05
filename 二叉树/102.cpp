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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*> qu;
        if(root!=NULL){
            qu.push(root);
        }
        int size=0;
        while(!qu.empty()){
            vector<int> temp;
            int size=qu.size();
            for(int i=0;i<size;i++){
                TreeNode*node=qu.front();
                temp.push_back(node->val);
                qu.pop();
                if(node->left){
                    qu.push(node->left);
                }
                if(node->right){
                    qu.push(node->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};