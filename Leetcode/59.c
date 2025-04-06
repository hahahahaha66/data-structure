#include<stdlib.h>
int n;
int **num=(int**)malloc(n*sizeof(int**));
for(int i=0;i<n;i++){
    num[i]=(int*)malloc(n*sizeof(int*));
}