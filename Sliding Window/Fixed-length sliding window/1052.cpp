#include <vector>
using namespace std;
class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int result = 0;
            for(int i = 0; i < customers.size(); i++) {
                if(grumpy[i] == 0) {
                    result += customers[i];
                    customers[i] = 0;
                }
            }
            int count = 0;
            int sum = 0;
            for(int i = 0; i < customers.size(); i++) {
                count += customers[i];
                if(i >= minutes) {
                    count -= customers[i - minutes];
                }
                if(i >= minutes - 1) {
                    sum = max(count,sum);
                }
            }
            return result + sum;
        }
    };