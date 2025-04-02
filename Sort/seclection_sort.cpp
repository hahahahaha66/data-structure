#include <iostream>
#include <random>
#include <vector>
using namespace std;
void selection_sort(vector<int>&array){
    for(int i=0;i<array.size()-1;i++){
        int min=i;
        for(int j=i+1;j<array.size();j++){
            if(array[min]>array[j]){
                min=j;
            }
            swap(array[i],array[min]);
        }
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
    selection_sort(array);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}