#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> result;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!result.empty()){
                char temp=result.top();
                if(temp==s[i]){
                    result.pop();
                }
                else{
                    result.push(s[i]);
                }
            }
            else{
                result.push(s[i]);
            }
        }
        string haha;
        stack<char> m;
        while(!result.empty()){
            char i=result.top();
            m.push(i);
            result.pop();
        }
        while(!m.empty()){
            char j=m.top();
            haha.push_back(j);
            m.pop();
        }
        return haha;
    }
};