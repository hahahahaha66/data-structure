#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            int left = 0;
            int result = 0;
            unordered_map<int, int> map;
            int currentsum = 0;
            for(int right = 0; right < nums.size(); right++) {
                map[nums[right]]++;
                currentsum +=nums[right];
                while (right > 0 && map[nums[right]] != 1) {
                    currentsum -=nums[left];
                    map[nums[left]]--;
                    left++;
                }
                result = max(result, currentsum);
            }
            return result;
        }
    }; 
    