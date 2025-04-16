#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int result = 0;
            int maxone = 0;
            int left = 0;
            int zero = 0;
            int n = nums.size();
            for(int right = 0; right < n; right++) {
                if(nums[right] == 0) {
                    zero++;
                }
                else {
                    maxone++;
                }
                while(zero > 1) {
                    if(nums[left] == 0) {
                        zero--;
                    }
                    else {
                        maxone--;
                    }
                    left++;
                }
                result = max(maxone, result);
            }
            if(result == n) {
                return result - 1;
            }
            return result;
        }
    };