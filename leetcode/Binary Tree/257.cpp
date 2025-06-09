#include <vector>
#include <queue>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归加回溯，实际上是利用了path传的形参，在递归返回时回到上一步，也就是回溯
class Solution {
public:
    void dfs(TreeNode* node,string path,vector<string>&result) {
        if(node == NULL) {
            return ;
        }
        if(path.empty()) {
            path = to_string(node->val);
        }
        else {
            path +="->" + to_string(node->val);
        }
        if(node->left == NULL && node->right == NULL) {
            result.push_back(path);
            return ;
        }
        if(node->left) dfs(node->left,path,result);
        if(node->right) dfs(node->right,path,result);
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        dfs(root,path,result);
        return result;
    }
};