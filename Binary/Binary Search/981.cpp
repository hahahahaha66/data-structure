#include <map>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;
class TimeMap {
public:
    unordered_map<string,map<int,string>> udp;
    int mintimestamp = INT_MAX;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        udp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!udp.count(key))
        {
            return "";
        }
        map<int, string>& temp = udp[key];
        auto it = temp.lower_bound(timestamp);

        if (it->first == timestamp)
        {
            return it->second;
        }
        else if (it == temp.begin() && it->first >timestamp)
        {
            return "";
        }
        --it;
        return it->second;
    }
};
