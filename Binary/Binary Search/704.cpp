#include <vector>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = -1;
            int right = nums.size();
            while(left + 1 < right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] < target)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            if (right < nums.size() && nums[right] == target)
            {
                return right;
            }
            return -1;
        }
    };