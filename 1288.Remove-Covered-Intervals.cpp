#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        });
        int curRight = 0;
        int coveredCount = 0;
        for (auto& interval : intervals) {
            if (interval[1] <= curRight) {
                ++coveredCount;
                continue;
            }
            curRight = max(curRight, interval[1]);
        }
        return intervals.size() - coveredCount;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> intervals = {{1,2},{1,3},{1,4}};
    cout << solution.removeCoveredIntervals(intervals) << endl; // 1
}