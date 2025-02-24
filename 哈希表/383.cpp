#include <unordered_map>
#include <string>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char,int> haha;
        for(char a : ransomNote){
            haha[a]++;
        }
        for(char b : magazine){
            if(haha.find(b)!=haha.end()){
                haha[b]--;
            }
        }
        for(auto &c :haha){
            if(c.second>0){
                return false;
            }
        }
        return true;
    }