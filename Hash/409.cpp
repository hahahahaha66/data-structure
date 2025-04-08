#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int longestPalindrome(string s) {
            unordered_map<char,int> map;
            for(char a : s) {
                map[a]++;
            }
            int count = 0;
            bool t = false;
            for(auto& i : map) {
                while(i.second >= 2) {
                    i.second -= 2;
                    count += 2;
                }
                if(i.second == 1) {
                    t = true;
                }
            }
            if(t) {
                count ++;
            }
            return count;
        }
    };