#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> result;
    string path;
    map<int,string> haha = {
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"},
    };
    void backtracking(string digits,int index) {
        if(path.size() == digits.size()) {
            result.push_back(path);
            return ; 
        }
        int j = digits[index] - '0';
        string& str = haha[j];
        for(char o : str) {
            path.push_back(o);
            backtracking(digits,index+1);
            path.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
        }
        else{
            backtracking(digits,0);
        }
        return result;
    }
};