#include <cstddef>
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
    //中序遍历
    //用空指针标记中节点
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root==NULL){
            return result;
        }
        st.push(root);
        while(!st.empty()){
            TreeNode*node=st.top();
            if(node!=NULL){
                st.pop();
                if(node->right!=NULL){
                    st.push(node->right);//右节点
                }
                st.push(node);//中节点
                st.push(NULL);
                if(node->left!=NULL){
                    st.push(node->left);//左节点
                }
            }
            else{
                st.pop();
                node=st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};