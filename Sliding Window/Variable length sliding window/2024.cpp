#include <string>
using namespace std;
class Solution {
    public:
        int maxConsecutiveAnswers(string answerKey, int k) {
            int numT = 0;
            int numF = 0;
            int result = 0;
            int left = 0;
            for (int right = 0; right < answerKey.size(); right++)
            {
                if (answerKey[right] == 'T')
                {
                    numT++;
                }
                else
                {
                    numF++;
                }
                int temp = min(numF, numT);
                while (temp > k)
                {
                    if (answerKey[left] == 'T')
                    {
                        numT--;
                    }
                    else
                    {
                        numF--;
                    }
                    temp = min(numF, numT);
                    left++;
                }
                result = max(right - left + 1, result);
            }
            return result;
        }
    };