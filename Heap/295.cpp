#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class MedianFinder {
public:
    vector<int> maxheap;
    vector<int> minheap;
    MedianFinder() {
    }
    
    void addNum(int num) {
       if(maxheap.empty() || num <= maxheap.front()) {
            maxheap.push_back(num);
            push_heap(maxheap.begin(),maxheap.end());
        }
       else {
            minheap.push_back(num);
            push_heap(minheap.begin(),minheap.end(),greater<>());
        }

       if(maxheap.size() < minheap.size()) {
            pop_heap(minheap.begin(),minheap.end(),greater<>());
            int moved = minheap.back();
            minheap.pop_back();

            maxheap.push_back(moved);
            push_heap(maxheap.begin(),maxheap.end());
        }
        else if(maxheap.size() > minheap.size() + 1) {
            pop_heap(maxheap.begin(),maxheap.end());
            int moved = maxheap.back();
            maxheap.pop_back();

            minheap.push_back(moved);
            push_heap(minheap.begin(),minheap.end(),greater<>());
        }
    }
    
    double findMedian() {
        int n = maxheap.size() + minheap.size();
        if(n % 2 == 0) {
            return ((double)maxheap.front() + (double)minheap.front()) / 2;
        }
        else {
            return (double)maxheap.front();
        }
    }
};