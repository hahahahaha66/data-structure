#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> ch;
        int n = 0;
        string res = "";
        for(char i : s) {
            if(isdigit(i)) {
                n = n * 10 + (i - '0');
            }
            else if(i == '[') {
                num.push(n);
                n = 0;
                ch.push(res);
                res = "";
            }
            else if(i == ']') {
                int count = num.top();
                num.pop();
                string temp = ch.top();
                ch.pop();
                while(count--) {
                    temp += res;
                }
                res = temp;
            }
            else res += i;
        }
        return res;
    }
};