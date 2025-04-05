#include <string>
#include <unordered_map>
using namespace std;
bool isAnagram(string s, string t) {
    int record[26]={0};
    for (int i = 0; i < s.size(); i++){
        record[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); i++){
        record[t[i]-'a']--;
    }
    int count=0;
    for (int i = 0; i < 26; i++){
        if(record[i]!=0){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        for(char i : s) {
            map[i]++;
        }
        for(char j : t) {
            map[j]--;
        }
        for(auto& o : map) {
            if(o.second != 0) {
                return false;
            }
        }
        return  true;
    }
};