#include <vector>
using namespace std;
class Solution {
    public:
        int count(int& num) {
            int count = 0;
            while (num != 0) {
                num /= 10;
                count++;
            }
            return count;
        }
        int findNumbers(vector<int>& nums) {
            int result = 0;
            for (int& n : nums) {
                int temp = count(n);
                if (temp % 2 == 0) {
                    result++;
                }
            }
            return result;
        }
    };