#include <vector>
using namespace std;
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int left = -1;
            int right = nums.size();
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] < 0) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
            int numleft = left + 1;
            left = -1;
            right = nums.size();
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= 0) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
            int numright = nums.size() - right;
            return numleft > numright ? numleft : numright;
        }
    };