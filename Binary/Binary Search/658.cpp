#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int left = 1;
        int right = 1;
        int mid = 0;
        int inst = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (arr.size() == k) {
            return std::vector<int>(arr);
        }
        if (inst == 0) {
            return std::vector<int>(arr.begin(), arr.begin() + k);
        }
        if (inst == arr.size()) {
            return vector<int>(arr.end() - k, arr.end());
        }
        if (abs(arr[inst] - x) >= abs(arr[inst - 1] - x))
            mid = inst - 1;
        else 
            mid = inst;
        result.push_back(arr[mid]);
        while(result.size() < k)
        {
            int ldiff = INT_MAX;
            int rdiff = INT_MAX;
            if (mid - left >= 0)
                ldiff = abs(x - arr[mid - left]);
            if(mid + right < arr.size())
                rdiff = abs(arr[mid + right] - x);

            if (ldiff > rdiff) {
                result.push_back(arr[mid + right]);
                right++;
            }
            else {
                result.push_back(arr[mid - left]);
                left++;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};