#include <iostream>
#include <random>
#include <vector>
using namespace std;
void bubble_sort(vector<int>&array){
    for(int i=0;i<array.size()-1;i++){
        for(int j=0;j<array.size()-1-i;j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}
int main(){
    vector<int> array(10);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,100);
    for(int &i : array){
        i=dis(gen);
        cout<<i<<" ";
    }
    cout<<endl;
    bubble_sort(array);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;
}