#include <vector>
using namespace std;
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int num0 = 0;
            int result = 0;
            int left = 0;
            for (int right = 0; right < nums.size(); right++)
            {
                if (nums[right] == 0)
                {
                    num0++;
                }
                while (num0 > k)
                {
                    if(nums[left] == 0)
                    {
                        num0--;
                    }
                    left++;
                }
                result = max(right - left + 1, result);
            }
            return result;
        }
    };