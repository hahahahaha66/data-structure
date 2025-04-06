void reverseString(char* s, int sSize) {
    int a=0,b=sSize-1;
    while(a<b){
        int temp=s[a];
        s[a]=s[b];
        s[b]=temp;
        a++;
        b--;
    }
}