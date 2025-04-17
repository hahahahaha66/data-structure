#include <vector>
using namespace std;
class Solution {
    public:
        int minSwaps(vector<int>& nums) {
            int n = nums.size();
            int totalone = 0;
            for(int i : nums) totalone += i;
    
            if(totalone == 0 && totalone == n) return 0;
    
            nums.insert(nums.end(),nums.begin(),nums.end());
    
            int maxnum = 0;
            int current = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(nums[i] == 1) {
                    current ++;
                }
                if(i >= totalone) {
                    if(nums[i - totalone] == 1) {
                        current --;
                    }
                }
                if(i >= totalone - 1) {
                    maxnum = max(current, maxnum);
                }
            }
            return totalone - maxnum;
        }
    };