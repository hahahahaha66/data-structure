#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> haha;
        int n=tokens.size();
        int count=0;
        for(string& token:tokens){
            int m;
            int n;
            if(token=="+"){
                m=haha.top(); haha.pop();
                n=haha.top(); haha.pop();
                haha.push(m+n);
            }
            else if(token=="-"){
                m=haha.top(); haha.pop();
                n=haha.top(); haha.pop();
                haha.push(n-m);
            }
            else if(token=="*"){
                m=haha.top(); haha.pop();
                n=haha.top(); haha.pop();
                haha.push(m*n);
            }
            else if(token=="/"){
                m=haha.top(); haha.pop();
                n=haha.top(); haha.pop();
                haha.push(n/m);
            }
            else{
                int temp=stoi(token);
                haha.push(temp);
            }
        }
        return haha.top();
    }
};