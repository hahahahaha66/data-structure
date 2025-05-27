#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int check(int current, vector<int>& weights, int& target)
    {
        int count = 1;
        int load = 0;
        for (int& i : weights) {
            if (load + i> current)
            {
                count++;
                load = 0;
            }
            load += i;
        }
        return target - count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()) - 1;;
        int right = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            int end = check(mid, weights, days);
            if (end >= 0) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};