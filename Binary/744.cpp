#include <vector>
using namespace std;
class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int left = -1;
            int right = letters.size();
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (letters[mid] <= target) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }
            if (right < letters.size()) {
                return letters[right];
            }
            return letters[0];
        }
    };