#include<stdlib.h>
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* returnArray = (int*)malloc(numsSize * sizeof(int)); 
    *returnSize = numsSize;
    int i = 0, j = numsSize - 1, k = numsSize - 1;
    
    while (i <= j) {
        int leftSquare = nums[i] * nums[i];
        int rightSquare = nums[j] * nums[j];
        
        if (leftSquare > rightSquare) {
            returnArray[k--] = leftSquare;
            i++;
        } else {
            returnArray[k--] = rightSquare;
            j--;
        }
    }
    return returnArray;
}
