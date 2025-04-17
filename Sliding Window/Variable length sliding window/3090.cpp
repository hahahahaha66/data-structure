#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int maximumLengthSubstring(string s) {
            int left = 0;
            int result = 0;
            int n = s.size();
            unordered_map<char, int> map;
            for(int right = 0; right < n; right++) {
                char c = s[right];
                map[c]++;
                while(map[c] > 2) {
                    map[s[left]]--;
                    left++;
                }
                result = max(result, right - left + 1);
            }
            return result;
        }
    };