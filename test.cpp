#include<iostream>
#include<vector>
using namespace std;
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
    cout << left << endl;
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
    cout << right << endl;
    return numleft > numright ? numleft : numright;
}
int main() {
    vector<int> nums = {-3,-2,-1,0,0,1,2};
    cout << maximumCount(nums) << endl;
}