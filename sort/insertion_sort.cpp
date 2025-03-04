#include <iostream>
#include <random>
#include <vector>
using namespace std;
void insertion_sort(vector<int>&array){
    for(int i=1;i<array.size();i++){
        int key=array[i];
        int j=i-1;
        while(j>=0&&key<array[j]){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
int main(){
    vector<int> array(10);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,100);
    for(int& i : array){
        i=dis(gen);
        cout<<i<<" ";
    }
    cout<<endl;
    insertion_sort(array);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}