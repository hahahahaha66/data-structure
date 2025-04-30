#include <vector>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int left = 0;
            long long result = 0;
            int count = 0;
            int max = 0;
            for (int i : nums) {
                if(i > max) {
                    max = i;
                }
            }
            for(int right = 0; right < nums.size(); right++) {
                if (nums[right] == max) {
                    count++;
                }
                while(count >= k) {
                    result += nums.size() - right;
                    if (nums[left] == max) {
                        count--;
                    }
                    left++;
                }
            }
            return result;
        }
    };