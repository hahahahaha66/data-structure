#include <unordered_map>
#include <vector>
using namespace std;
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int,int> haha;
        for(int a : nums1) {
            for(int b : nums2) {
                haha[a+b]++;
            }
        }
        int count=0;
        for(int c : nums3) {
            for(int d : nums4){
                if(haha.find(-(c+d)) != haha.end()) {
                    count+=haha[-(c+d)];
                }
            }
        }
        return count;
    }