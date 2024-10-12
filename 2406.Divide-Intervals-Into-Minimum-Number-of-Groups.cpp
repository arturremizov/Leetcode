#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (auto interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int result = 0;
        while (i < intervals.size()) {
            if (start[i] <= end[j]) {
                ++i;
            } else {
                ++j;
            }
            result = max(result, i - j);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> intervals = {{5,10}, {6,8}, {1,5}, {2,3}, {1,10}};
    cout << solution.minGroups(intervals) << endl; // 3
}