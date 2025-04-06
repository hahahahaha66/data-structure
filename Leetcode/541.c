void swap(char*s,int len){
    int a=0,b=len-1;
    while(a<b){
        int temp=s[a];
        s[a]=s[b];
        s[b]=temp;
        a++;
        b--;
    }
}
char* reverseStr(char* s, int k) {
    int len=strlen(s);
    int n=0;
    while(len-n>2*k){
        swap(s+n,k);
        n+=2*k;
    }
    if(len-n<k){
        swap(s+n,strlen(s+n));
    }
    else{
        swap(s+n,k);
    }
    return s;
}