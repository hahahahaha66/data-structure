#include <vector>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result = 0;
        int total = k * threshold;
        int count = 0;
        for (int i = 0; i < k; i++) {
            count += arr[i];
        }
        if (count >= total) {
            result++;
        }
        for (int i = k; i < arr.size(); i++) {
            count += arr[i];
            count -= arr[i - k];
            if (count >= total) {
                result++;
            }
        }
        return result;
    }
};