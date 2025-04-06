char* reverseWords(char* s) {
    int a,b=0;
    int n=strlen(s);
    for(a=0;a<n;a++){
        if(a>0&&s[a-1]==' '&&s[a]==' '){
            continue;
        }
        s[b]=s[a];
        b++;
    }
    n=b;
    if (n > 0 && s[n - 1] == ' ') {
        n--;
    }
    s[n] = '\0'; 
    a=0;
    b=n-1;
    while(a<b){
        char temp=s[a];
        s[a]=s[b];
        s[b]=temp;
        a++;
        b--;
    }
    a=b=0;
    for(a=0;a<=n;a++){
        if(s[a]==' '||s[a]=='\0'){
            int m=b;
            int k=a-1;
            while(m<k){
                int temp=s[m];
                s[m]=s[k];
                s[k]=temp;
                m++;
                k--;
            }
            b=a+1;
        }
    }
    if (n > 0 && s[n - 1] == ' ') { 
        n--;
    }
    s[n] = '\0';
    return s;
}