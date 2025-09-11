#include <string>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int fina;
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
                fina = count;
            }
        }
        for (int i = k; i < s.size(); i++) {
            char in = s[i];
            if (in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u') {
                count++;
            }
            char out = s[i - k];
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' || out == 'u') {
                count--;
            }
            if (count > fina) fina = count;
        }
        return fina;
    }
};