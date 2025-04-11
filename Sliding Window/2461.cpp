#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        long long maximumSubarraySum(vector<int>& nums, int k) {
            long long result = 0;
            long long sum = 0;
            unordered_map<int,int> map;
            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                map[nums[i]] ++;
                if(i >= k) {
                    sum -= nums[i - k];
                    map[nums[i - k]] --;
                    if(map[nums[i - k]] == 0) {
                        map.erase(nums[i - k]);
                    }
                }
                if(i > k - 2 && map.size() == k) {
                    result = max(sum, result);
                }
            }
            return result;
        }
    };