#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
            vector<int> result;
            sort(nums.begin(), nums.end());
            for (int j = 1; j < nums.size(); j++) {
                nums[j] += nums[j - 1];
            }
            for (int i = 0; i < queries.size(); i++) {
                int k = queries[i];
                int left = -1;
                int right = nums.size();
                while (left + 1 < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] <= k) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
                result.push_back(left + 1);
            }
            return result;
        }
    };