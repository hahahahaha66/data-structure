bool repeatedSubstringPattern(char* s) {
    int m,n;
    int len=strlen(s);
    int *arr=(int *)malloc(sizeof(int)*len);
    arr[0]=0;
    for(m=1,n=0;m<len;m++){
        while(n>0&&s[m]!=s[n]){
            n = arr[n - 1];
        }
        if(s[m]==s[n]){
            n++;
        }
        arr[m]=n;
    }
    bool a=false;
    if(arr[len-1]){
        a=len%(len-arr[len-1])==0?true:false;
    }
    free(arr);
    return a;
}
