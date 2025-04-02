#include <iostream>
#include <random>
#include <vector>
using namespace std;
vector<int> merge(vector<int>&left,vector<int>&right){
    vector<int>result;
    int i=0;
    int j=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<=right[j]){
            result.push_back(left[i]);
            i++;
        }
        else{
            result.push_back(right[j]);
            j++;
        }
    }
    while(j<right.size()){
        result.push_back(right[j]);
        j++;
    }
    while(i<left.size()){
        result.push_back(left[i]);
        i++;
    }
    return result;
}
vector<int> merge_sort(vector<int>&array,int left,int right){
    if(right==left){
        return {array[left]};
    }
    int mid=left+(right-left)/2;
    vector<int>left_half=merge_sort(array,left,mid);
    vector<int>right_half=merge_sort(array,mid+1,right);
    return merge(left_half,right_half);
}
int main (){
    vector<int> array(10);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,100);
    for(int& i : array){
        i=dis(gen);
        cout<<i<<" ";
    }
    cout<<endl;
    array=merge_sort(array,0,array.size()-1);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
