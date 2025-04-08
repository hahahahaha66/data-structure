#include <string>
using namespace std;
class Solution {
    public:
        bool is(char a) {
            return a == 'a' || a == 'e'|| a == 'i' || a == 'o' || a == 'u';
        }
        int maxVowels(string s, int k) {
            int count = 0;
            int max = 0;
            for(int i = 0; i < s.size(); i++) {
                if(is(s[i])) count++;
                if((i >= k) && is(s[i - k])) count--;
                if(count > max) max = count;
            }
            return max;
        }
    };
