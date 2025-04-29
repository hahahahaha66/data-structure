#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
            int result = 0;
            sort(arr2.begin(), arr2.end());
            for (int i = 0; i < arr1.size(); i++) {
                int k = arr1[i];
                int left = -1;
                int right = arr2.size();
                while (left + 1 < right) {
                    int mid = left + (right - left) / 2;
                    if (arr2[mid] < k) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
                bool judge = true;
                if (right < arr2.size() && abs(arr2[right] - k) <= d) {
                    judge = false;
                }
                if (left > -1 && abs(arr2[left] - k) <= d) {
                    judge = false;
                }
                if (judge) result++;
            }
            return result;
        }
    };