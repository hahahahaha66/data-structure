#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>  

using namespace std;
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> price_to_beauty;
        for (auto& item : items) {
            price_to_beauty[item[0]] = max(price_to_beauty[item[0]], item[1]);
        }

        vector<pair<int, int>> price_beauty;
        int max_beauty = 0;
        for (auto& [a,b] : price_to_beauty) {
            max_beauty = max(max_beauty, b);
            price_beauty.emplace_back(a, max_beauty);
        }

        vector<int> result;
        for (int p : queries) {
            auto it = upper_bound(price_beauty.begin(), price_beauty.end(), make_pair(p, INT_MAX));
            if (it == price_beauty.begin()) {
                result.emplace_back(0);
            }
            else {
                result.emplace_back((--it)->second);
            }
        }
        return result;
    }
};