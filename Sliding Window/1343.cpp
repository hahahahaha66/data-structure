#include <vector>
using namespace std;
class Solution {
    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            int count = 0;
            int n = 0;
            for(int i = 0; i < arr.size(); i++) {
                count += arr[i];
                if(i >= k) count -= arr[i - k];
                if(i >= k - 1 && (count >= (threshold * k))) {
                    n++;
                }
            }
            return n;
        }
    };