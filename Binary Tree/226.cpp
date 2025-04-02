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
//递归前序遍历
//中序不太好写
//后序的话，就是把交换的部分放在遍历后
class Solution1 {
public:
    void traversal(TreeNode* cur){
        if(cur == NULL) {
            return ;
        }
        TreeNode* node=cur->left;
        cur->left=cur->right;
        cur->right=node;
        traversal(cur->left);
        traversal(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        traversal(root);
        return root;
    }
};