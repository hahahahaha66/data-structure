#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long tripsnum(vector<int>&time, long long totaltime) {
        long long count = 0;
        for (int& i : time) {
            count += (totaltime / i);
        }
        return count;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = -1;
        long long right = (long long)*min_element(time.begin(), time.end()) * totalTrips + 1;
        while (left + 1< right) {
            long long mid = left + (right - left) / 2;
            if (tripsnum(time, mid) >= totalTrips) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return right;
    }
};