#include <stack>
using namespace std;
class MYQueue {
public:
    stack<int> stin;
    stack<int> stout;
    
    void push(int x) {
        stin.push(x);
    }
    
    int pop() {
        if(stout.empty()){
            while(!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
        int result=stout.top();
        stout.pop();
        return result;
    }
    
    int peek() {
        int result=this->pop();
        stout.push(result);
        return result;
    }
    
    bool empty() {
        return stin.empty()&&stout.empty();
    }
};
    