#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=10;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        nums[i]=i;
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}