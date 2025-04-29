#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            sort(potions.begin(), potions.end());
    
            vector<int> result;
            for (int i = 0; i < spells.size(); i++) {
                long long k = spells[i];
                int left = -1;
                int right = potions.size();
                while (left + 1 < right) {
                    int mid = left + (right - left) / 2;
                    if (k * potions[mid] < success) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
                int n = potions.size() - right;
                result.push_back(n);
            }
            return result;
        }
    };