#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        vector<int> result(n, -1);
        unordered_map<int, int> fullLakes; // lake -> day
        set<int> dryDays;
        int dryCount = 0;
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);
                result[i] = 1;
            } else {
                if (fullLakes.count(lake)) {
                    int lastRainDay = fullLakes[lake];
                    auto it = dryDays.lower_bound(lastRainDay);
                    if (it == dryDays.end()) return {};
                    int dryDay = *it;
                    dryDays.erase(dryDay);
                    result[dryDay] = lake;
                }
                fullLakes[lake] = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> rains = {1,2,0,0,2,1};
    vector<int> result = solution.avoidFlood(rains); // [-1,-1,2,1,-1,-1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}