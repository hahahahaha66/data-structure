#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int m,int n,int k) {
        if(path.size() == k) {
            result.push_back(path);
            return ;
        }
        for(int i = m;i <= n;i++) {
            path.push_back(i);
            backtracking(i + 1,n,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(1,n,k);
        return result;
    }
};