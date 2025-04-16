#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int left = 0;
            int result = 0;
            int maxnum = 0;
            int n = s.size();
            unordered_map<char, int> map;
            for(int right = 0; right < n; right++) {
                char c = s[right];
                map[c]++;
                maxnum++;
                while(map[c] > 1) {
                    map[s[left]]--;
                    maxnum--;
                    left++;
                }
                result = max(maxnum, result);
            }
            return result;
        }
    };