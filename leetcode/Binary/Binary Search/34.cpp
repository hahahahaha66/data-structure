#include <vector>
using namespace std;
//关键在于循环不变量，每一次循环，不变的量是获得左或右区间的与target的大小关系
//这也是为什么left+1,right-1
//闭区间，左区间是所有的小于target的量，右区间是所有的大于等于target的量
class Solution1 {
    int found(vector<int>&nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = found(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = found(nums, target + 1) - 1;
        return {start, end};
    }
};
//开区间的写法
//开区间的初始化为永不访问的变量，且判断条件为中间无数可取
//也就是开区间中间没有数，而又不能取区间边界上的数
class Solution2 {
    public:
        int found(vector<int>& nums, int target) {
            int left = -1;
            int right = nums.size();
            while (left + 1 < right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > target) {
                    right = mid;
                }
                else {
                    left = mid;
                }
            }
            return left;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            int end = found(nums, target);
            if (end == -1 || nums[end] != target) {
                return {-1, -1};
            }
            int start = found(nums, target - 1) + 1;
            return {start, end};
        }
    };