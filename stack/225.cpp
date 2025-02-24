#include <queue>
using namespace std;
class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size=que.size();
        size--;
        while(size--){
            que.push(que.front());
            que.pop();
        }
        int result=que.front();
        que.pop();
        return result;
    }
    
    int top() {
        int size=que.size();
        size--;
        while(size--){
            que.push(que.front());
            que.pop();
        }
        int result=que.front();
        que.push(que.front());//这里是还原原来的队列顺序，以方便下一步操作
        que.pop();
        return result;
    }
    
    bool empty() {
        return que.empty();
    }
};