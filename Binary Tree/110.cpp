#include <vector>
#include <queue>
#include <cmath>
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
    int checkheight(TreeNode* node) {
        if(node == NULL) return 0;

        int leftdepth = checkheight(node->left);
        if(leftdepth == -1) return -1;

        int rightdepth = checkheight(node->right);
        if(rightdepth == -1) return -1;

        if(abs(leftdepth-rightdepth) > 1) return -1;
        
        return 1 + max(leftdepth,rightdepth);
    }
    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }
};