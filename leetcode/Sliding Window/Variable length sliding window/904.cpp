#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int basket1 = 0;
            int type1 = -1;
            int basket2 = 0;
            int type2 = -1;
            int left = 0;
            int result = 0;
            for(int right = 0; right < fruits.size(); right++) {
                if(fruits[right] == type1) {
                    basket1++;
                }
                else if(fruits[right] == type2) {
                    basket2++;
                }
                else {
                    while (basket1 > 0 && basket2 > 0) {
                        int f = fruits[left];
                        if(f == type1) {
                            basket1--;
                        }
                        else {
                            basket2--;
                        }
                        left++;
                    }
                    if(basket1 == 0) {
                        type1 = fruits[right];
                        basket1 = 1;
                    }
                    else {
                        type2 = fruits[right];
                        basket2 = 1;
                    }
                }
                result = max(result, basket1 + basket2);
            }
            return result;
        }
    };