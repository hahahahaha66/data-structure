int totalFruit(int* fruits, int fruitsSize) {
    int i=0,j=0;
    int num=0;
    int max=0;
    int count=0;
    int a,b;
    for(j=0;j<fruitsSize;j++){
        if(count==0){
            a=fruits[j];
            count++;
        }
        if(fruits[j]!=a&&count==1){
            b=fruits[j];
            count++;
        }
        i=j;
        if(fruits[j]==a||fruits[j]==b){
            num++;
            if(max<num){
                max=num;
            }
        }
        else{
            i--;
            a=fruits[i];
            while(fruits[--i]==a);
            b=fruits[j];
            num=j-i;
            if(max<num){
                max=num;
            }
        }
    }
    return max;
}