#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int f(string s) {
            char min = 'z';
            int count = 0;
            for (char c : s) {
                if (c < min) {
                    min = c;
                    count = 1;
                }
                else if (c == min) {
                    count++;
                }
            }
            return count;
        }
        vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            vector<int> result;
            vector<int> wordFreq;
            for (const string& word : words) {
                wordFreq.push_back(f(word));
            }
            
            sort(wordFreq.begin(), wordFreq.end());
            for (int i = 0 ; i < queries.size(); i++) {
                int left = -1;
                int right = words.size();
                while (left + 1 < right) {
                    int mid = left + (right - left) / 2;
                    if (f(queries[i]) < wordFreq[mid]) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
                result.push_back(words.size() - right);
            }
            return result;
        }
    };