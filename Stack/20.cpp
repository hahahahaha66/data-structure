#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i : s) {
            if(st.empty()) {
                st.push(i);
                continue;
            }
            if(i == ')') {
                if(st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
            else if(i == ']') {
                if(st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
            else if(i == '}') {
                if(st.top() == '{') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
            else {
                st.push(i);
            }
        }
        return st.empty();
    }
};