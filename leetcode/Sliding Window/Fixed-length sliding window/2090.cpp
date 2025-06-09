#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> getAverages(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> result(n, -1);
            if(n < (2 * k) + 1) return result;
    
            //计算前缀和
            vector<long long> prefixnum(n + 1, 0);
            for(int i = 0; i < n; i++) {
                prefixnum[i + 1] = prefixnum[i] + nums[i];
            }
    
            for(int j = k; j < n - k; j++){
                int left = j - k;
                int right = j + k;
                long long total = prefixnum[right + 1] - prefixnum[left];
                result[j] =total / ((2 * k) + 1);
            }
            return result;
        }
    };