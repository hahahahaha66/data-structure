#include<stdio.h>
void quick_sort(int *arr,int len){
    int mid=arr[len/2];
    int left=0;
    int right=len-1;
    while(left<right){
        while(arr[left]<mid) left++;
        while(arr[right]>mid) right--;
        if(left<right){
            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
        }
    }
    quick_sort(arr,right+1);
    quick_sort(arr+left,len-left);
}