#include <vector>
using namespace std;
class Solution1 {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            vector<int> result(code.size(), 0);
            vector<int> index(code.size() + 1, 0);
            for(int i = 0; i < code.size(); i++) {
                index[i + 1] = index[i] + code[i];
            }
            if(k > 0) {
                for(int i = 0; i < code.size(); i++) {
                    if((code.size() - i - 1) <= k) {
                        result[i] = index[index.size() - 1] - index[i + 1] + index[(k - (code.size() - i - 1))];
                    }
                    else {
                        result[i] = index[i + k + 1] - index[i + 1];
                    }
                }
            }
            else if(k < 0) {
                k = - k;
                for(int i = 0; i < code.size(); i++) {
                    if(i >= k) {
                        result[i] = index[i] - index[i - k];
                    }
                    else {
                        result[i] = index[index.size() - 1] - index[code.size() - (k - i)] + index[i];
                    }
                }
            }
           return result;
        }
    };

class Solution2 {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            int n = code.size();
            vector<int>result(n, 0);
            if(k == 0) {
                return result;
            }
            int sum = 0;
            int start = 0;
            int end = 0;
        
            if(k > 0) {
                for(int i = 1; i <= k; i++) {
                    sum += code[i % n];
                }
                for(int i = 0; i < n; i++) {
                    result[i] = sum;
                    sum -= code[(i + 1) % n];
                    sum += code[(i + k + 1) % n];
                }
            }
            else {
                k = -k;
                for(int i = 1; i <= k; i++) {
                    sum += code[(n - i) % n];
                }
                for(int i = 0; i < n; i++) {
                    result[i] = sum;
                    sum -= code[(n - k + i) % n];
                    sum += code[i % n];
                }
            }
            return result;
        }
    };