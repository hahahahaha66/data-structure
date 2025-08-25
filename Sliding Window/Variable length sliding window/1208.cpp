#include <string>
using namespace std;
class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) {
            int left = 0;
            int currentcost = 0;
            int n = s.size();
            int result = 0;
            for (int right = 0; right < n; right++) {
                currentcost += abs(t[right] - s[right]);
                while (currentcost > maxCost) {
                    currentcost -= abs(t[left] - s[left]);
                    left++;
                }
                result = max(result, right - left + 1);
            }
            return result;
        }
    };