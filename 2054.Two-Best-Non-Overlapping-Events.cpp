#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        unordered_map<string, int> memo;
        return helper(events, 0, 2, memo);
    }
private:
    int helper(vector<vector<int>>& events, int i, int remaining, unordered_map<string, int>& memo) {
        string key = to_string(i) + "," + to_string(remaining);
        if (memo.count(key)) return memo[key];
        if (i == events.size() || remaining == 0) return 0;
        // skip event
        int result = helper(events, i + 1, remaining, memo); 
        // include event
        int nextIndex = binarySearch(events, events[i][1] + 1);
        result = max(result, events[i][2] + helper(events, nextIndex, remaining - 1, memo)); 
        memo[key] = result;
        return result;
    }

    int binarySearch(vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (right + left) / 2;
            if (events[mid][0] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> events = {{1,3,2}, {4,5,2}, {2,4,3}};
    cout << solution.maxTwoEvents(events) << endl; // 4
}