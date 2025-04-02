#include <iostream>
#include <random>
#include <vector>
using namespace std;
void shell_sort(vector<int>&array){
    int n=array.size();
    int gap=n/2;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int key=array[i];
            int j=i;
            while(j>=gap&&array[j-gap]>key){
                array[j]=array[j-gap];
                j-=gap;
            }
            array[j]=key;
        }
        gap/=2;
    }
}
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,100);
    vector<int> array(10);
    for(int& i : array){
        i=dis(gen);
        cout<<i<<" ";
    }
    cout<<endl;
    shell_sort(array);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}