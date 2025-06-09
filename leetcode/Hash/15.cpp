#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> haha;
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]>0) right--;
                else if(nums[left]+nums[right]+nums[i]<0) left++;
                else{
                    haha.push_back(vector<int>{nums[left],nums[i],nums[right]});
                    while(right > left && nums[left]==nums[left+1]) left++;
                    while(right > left && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return haha;
    }