#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {            
            
            int n = nums.size();
            vector<int> result;
            int num[101] = {0};
            int negativenum = 0;
    
            for(int i = 0; i < k; i++) {
                if(nums[i] < 0) {
                    negativenum++;
                }
                num[nums[i] + 50] ++;
            }
    
            for(int i = 0; i <= n - k; i++) {
                if(x > negativenum) {
                    result.push_back(0);
                }
                else {
                    int count = x;
                    int j = 0;
                    for(;j < 101; j++) {
                        if(num[j] >= count) break;
                        count -= num[j];
                    }
                    result.push_back(j - 50);
                }
                
                if(i + k < n) {
                    if(nums[i] < 0) {
                        negativenum--;
                    }
                    if(nums[i + k] < 0) {
                        negativenum++;
                    }
                    num[nums[i] + 50]--;
                    num[nums[i + k] + 50]++;
                }
            }
            return result;
        }
    };