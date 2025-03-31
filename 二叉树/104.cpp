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
//迭代，伪后序
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int result=0;
        if(root==NULL){
            return result;
        }
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                if(node->right){
                    que.push(node->right);
                }
                if(node->left){
                    que.push(node->left);
                }
            }
            result++;
        }
        return result;
    }
};
//递归，后序
class Solution2 {
public:
    int getdepth (TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        int depth = 1 + max(leftdepth,rightdepth);
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};
//递归，前序
class Solution {
public:
    int result = 0;
    void getdepth(TreeNode* node,int depth) {
        result = result > depth ? result : depth;

        if(node->left == NULL && node->right == NULL) return;

        if(node->left) {
            depth++;
            getdepth(node->left,depth);
            depth--;
        }
        if(node->right) {
            depth++;
            getdepth(node->right,depth);
            depth--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        getdepth(root,1);
        return result;
    }
};