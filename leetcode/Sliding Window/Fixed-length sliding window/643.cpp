#include <vector>
using namespace std;
class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int count = 0;
            int max = 0;
            for(int i = 0; i < nums.size(); i++) {
                count += nums[i];
                if(i >= k) count -= nums[i - k];
                if(i < k) {
                    max = count;
                    continue;
                }
                if(count > max) max = count;
            }
            return (double)max / k; 
        }
    };