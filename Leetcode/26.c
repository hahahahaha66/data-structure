int removeDuplicates(int* nums, int numsSize) {
    int i,j=0;
    int count=0;
    for(i=1;i<numsSize;i++){
        if(nums[i]==nums[j]){
            count++;
            continue;
        }
        nums[++j]=nums[i];
    }
    return numsSize-count;
}