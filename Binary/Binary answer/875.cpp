#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int check(int speed, vector<int>& piles, int h) {
        long long hour = 0;
        for (int& i : piles) {
            hour += (i + speed - 1) / speed;
        }
        return h - hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end()) + 1;
        int left = 0;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, piles, h) >= 0) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};