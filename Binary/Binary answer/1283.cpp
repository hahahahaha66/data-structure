#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculation(vector<int>& nums, int divisor) {
        int count = 0;
        for (auto& it : nums) {
            count += (it + divisor - 1) / divisor;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (calculation(nums, mid) > threshold) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return right;
    }
};