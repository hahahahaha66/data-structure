void moveZeroes(int* nums, int numsSize) {
    int i,j=0;
    int count=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[j++]=nums[i];
            continue;
        }
        count++;
    }
    for(i=numsSize-count;i<numsSize;i++){
        nums[i]=0;
    }
}