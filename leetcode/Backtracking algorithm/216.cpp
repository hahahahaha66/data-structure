#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int m,int n,int k) {
        int count = 0;
        if(path.size() == k) {
            for(int j : path) {
                count += j;
            }
            if(count == n ){
                result.push_back(path);
                return ;
            }
        }
        
        if(count > n) {
            return ;
        }

        for(int i = m; i <= 9; i++) {
            path.push_back(i);
            backtracking(i + 1,n,k);
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1,n,k);
        return result;
    }
};
