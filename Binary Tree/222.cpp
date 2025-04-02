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
//普通迭代
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == NULL) {
            return 0;
        }
        que.push(root);
        int count = 0;
        while(!que.empty()) {
            int size = que.size();
            for(int i = 0;i < size;i++) {
                TreeNode* node = que.front();
                que.pop();
                count+=1;
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
            }
        }
        return count;
    }
};
//普通递归
class Solution2 {
public:
    int getcount(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        int leftnum = getcount(node->left);
        int rightnum = getcount(node->right);
        return leftnum+rightnum+1;
    }
    int countNodes(TreeNode* root) {
        return getcount(root);
    }
};
//完全二叉树递归
class Solution3 {
public:
    int getcount(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        TreeNode* leftnode = node->left;
        TreeNode* rightnode = node->right;
        int leftdepth = 0;
        int rightdepth = 0;
        while(leftnode) {
            leftnode = leftnode->left;
            leftdepth++;
        }
        while(rightnode) {
            rightnode = rightnode->right;
            rightdepth++;
        }
        if(leftdepth == rightdepth) {
            return (2<<leftdepth) - 1;
        }
        int leftcount = getcount(node->left);
        int rightcount = getcount(node->right);
        int count = leftcount + rightcount;
        return count+1;
    }
    int countNodes(TreeNode* root) {
        return getcount(root);
    }
};