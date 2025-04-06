int minSubArrayLen(int target, int* nums, int numsSize) {
    int left=0,right=0,sum=0,length,MIN=1000000000;
    for(right=0;right<numsSize;right++){
            sum+=nums[right];
            while(sum>=target){
                length=right-left+1;
                if(length<MIN){
                    MIN=length;
                }
                sum-=nums[left];
                left++;
            }    
    }
    return (MIN==1000000000)?0:MIN;
}