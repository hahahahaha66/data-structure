#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
            int left = 0;
            unordered_map<int, int> map;
            int result = 0;
            for (int right = 0; right < nums.size(); right++) {
                map[nums[right]]++;
                while (map[nums[right]] > k) {
                    map[nums[left]]--;
                    left++;
                }
                result = max(result, right - left + 1);
            }
            return result;
        }
    };