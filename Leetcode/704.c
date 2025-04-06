int search(int* nums, int numsSize, int target) {
    int n=numsSize/2;
    int left=0;
    int right=numsSize;
    int x=(left+right)/2;
    for(int i=0;i<=n;i++){
        x=(left+right)/2;
        if(target==nums[x]){
            return x;
        }
        else if(target>nums[x]){
            left=x;
        }
        else if(target<nums[x]){
            right=x;
        }
    }
    return -1;
}