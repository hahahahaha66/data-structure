#include <string>
using namespace std;
//O(N*K)
class Solution1 {
    public:
        int minimumRecolors(string blocks, int k) {
            int min = 1000000;
            for(int i = k - 1; i < blocks.size(); i++) {
                int temp_min = 0;
                int left = i - k + 1;
                int right = i;
                for(int j = left; j <= right; j++) {
                    if(blocks[j] == 'W'){
                        temp_min ++;
                    }
                }
                if(temp_min < min) {
                    min = temp_min;
                }
            }
            return min;
        }
    };

//O(N)
class Solution2 {
    public:
        int minimumRecolors(string blocks, int k) {
            int count = 0;
            for(int i = 0; i < k; i++) {
                if(blocks[i] == 'W') {
                    count++;
                }
            }
    
            int minnum = count;
        
            for(int i = k; i < blocks.size(); i++) {
                if(blocks[i] == 'W') count++;
                if(blocks[i - k] == 'W') count--;
                minnum = min(count, minnum);
            }
    
            return minnum;
        }
    };