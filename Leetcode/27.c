int removeElement(int* nums, int numsSize, int val) {
    int j=0;
    int i;
    int count=0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==val){
            count++;
            continue;
        }
        nums[j]=nums[i];
        j++;
    }
    return numsSize-count;
}