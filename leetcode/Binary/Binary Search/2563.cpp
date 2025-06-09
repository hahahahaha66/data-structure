#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long result = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            int findlower = lower - nums[i];
            int findupper = upper - nums[i];
            auto start = nums.begin() + i + 1;
            auto end = nums.end();
            int finalleft = lower_bound(start, end, findlower) - nums.begin();
            int finalright = upper_bound(start, end, findupper) - nums.begin();
            result += (finalright - finalleft);
        }
        return result;
    }
};