// 暴力求解
#include <stdatomic.h>
int strStr(char* haystack, char* needle) {
    for(int i=0;i<strlen(haystack);i++){
        if(haystack[i]==needle[0]){
            int h=i;
            int j=0;
            while(haystack[++h]==needle[++j]&&haystack[h]!='\0'&&needle[j]!='\0');
            if(needle[j]=='\0'){
                return i;
            }
        }
    }
    return -1;
}
//KMP
int strStr(char* haystack, char* needle) {
    int n=strlen(needle);
    int m=strlen(haystack);
    int* arr=(int*)malloc(sizeof(int)*n);
    arr[0]=0;
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0&&needle[j]!=needle[i]){
            j=arr[j-1];
        }
        if(needle[i]==needle[j]){
            j++;
        }
        arr[i]=j;
    }
    for(int i=0,j=0;i<m;i++){
        while(j>0&&needle[j]!=haystack[i]){
            j=arr[j-1];
        }
        if(needle[j]==haystack[i]){
            j++;
        }
        if(j==n){
            free(arr);
            return i-n+1;
        }
    }
    free(arr);
    return -1;
}