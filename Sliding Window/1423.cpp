#include <vector>
#include <climits>
using namespace std;
//使用前缀和
class Solution1 {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int result = INT_MAX;
            int sum = 0;
            int l = cardPoints.size() - k;
            vector<int> index(cardPoints.size() + 1, 0);
            for(int i = 0; i < cardPoints.size(); i++) {
                index[i + 1] = index[i] + cardPoints[i];
            }
    
            for(int j = 0; j < k + 1; j++) {
                sum = index[j + l] - index[j];
                result = min(sum, result);
            }
    
            return index[cardPoints.size()] - result;
        }
    };

//直接滑动窗口
class Solution2 {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int result = INT_MAX;
            int total = 0;
            int count = 0;
            for(int i = 0; i < cardPoints.size(); i++) {
                total += cardPoints[i];
                count += cardPoints[i];
                if(i >= cardPoints.size() - k) {
                    count -= cardPoints[i - cardPoints.size() + k];
                }
                if(i >= cardPoints.size() - k - 1) {
                    result = min(result, count);
                }
            }
            
            if(cardPoints.size() == k) {
                return total;
            }
            
            return total - result;
        }
    };