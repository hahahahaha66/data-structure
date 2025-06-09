#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(char i : s) {
            map[i]++;
        }
        for(int j = 0; j < s.size(); j++) {
            if(map[s[j]] == 1) {
                return j;
            }
        }
        return -1;
    }
};