#include <algorithm>
#include <string>
#include <climits>
using namespace std;
class Solution {
    public:
        int minFlips(string s) {
            int n = s.size();
            s += s;
            int oddwrongnum = 0;
            int evenwrongnum = 0;
            int result = INT_MAX;
            for(int i = 0; i < 2 * n; i++) {
                char ecpectedodd = (i % 2) ? '0' : '1';//奇数位为0
                char ecpectedeven = (i % 2) ? '1' : '0';//偶数位为0
                if(s[i] != ecpectedodd) oddwrongnum++;
                if(s[i] != ecpectedeven) evenwrongnum++;
    
                if(i >= n) {
                    char ecpectedodd = ((i - n) % 2) ? '0' : '1';
                    char ecpectedeven = ((i - n) % 2) ? '1' : '0';
                    if(s[i - n] != ecpectedodd) oddwrongnum--;
                    if(s[i - n] != ecpectedeven) evenwrongnum--;
                }
    
                if(i >= n - 1) {
                    result = min({result, oddwrongnum, evenwrongnum});
                }
            }
            return result;
        }
    };