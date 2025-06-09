#include <deque>
#include <vector>
using namespace std;
class MyQueue{
    public:
    deque<int> que;
    void pop(int value){
        if(!que.empty()&&value==que.front()){
            que.pop_front();
        }
    }
    void push(int value){
        while(!que.empty()&&value>que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }
    int front(){
        return que.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue haha;
        vector<int> result;
        for(int i=0;i<k;i++){
            haha.push(nums[i]);
        }
        result.push_back(haha.front());
        for(int i=k;i<nums.size();i++){
            haha.pop(nums[i-k]);
            haha.push(nums[i]);
            result.push_back(haha.front());
        }
        return result;
    }
};