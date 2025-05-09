#include <vector>
#include <unordered_map>
using namespace std;
class RangeFreqQuery {
    public:
        unordered_map<int, vector<int>> pos;
    
        RangeFreqQuery(vector<int>& arr) {
            for (int i = 0; i < arr.size(); i++) {
                pos[arr[i]].push_back(i);
            }
        }
        
        int query(int left, int right, int value) {
            if (!pos.count(value)) return 0;
            const auto& indices = pos[value];
            
            int l = -1, r = indices.size();
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (indices[m] >= left) r = m;
                else l = m;
            }
            int low = r;
    
            l = -1; r = indices.size();
            while (l + 1 < r) {
                int m = (l + r) / 2;
                if (indices[m] > right) r = m;
                else l = m;
            }
            int high = r;
    
            return high - low;
        }
    };
    