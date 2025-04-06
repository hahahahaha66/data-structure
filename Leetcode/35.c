int searchInsert(int* nums, int numsSize, int target) {
    int right=numsSize-1;
    int left=0;
    int temp;
    while(left<=right){
        temp=(right+left)/2;
        if(nums[temp]>target){
            right=temp-1;
        }
        else if(nums[temp]<target){
            left=temp+1;
        }
        else{
            return temp;
        }
    }
    return left;
}