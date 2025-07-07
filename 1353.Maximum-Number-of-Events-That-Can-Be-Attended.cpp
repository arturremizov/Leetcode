#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = 0;
        for (vector<int>& event : events) {
            maxDay = max(maxDay, event[1]);
        }
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> minHeap;
        int result = 0;
        int eventIndex = 0;
        for (int currentDay = 0; currentDay <= maxDay; ++currentDay) {
            while (eventIndex < events.size() && events[eventIndex][0] <= currentDay) {
                minHeap.push(events[eventIndex][1]);
                ++eventIndex;
            }
            while (!minHeap.empty() && minHeap.top() < currentDay) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                minHeap.pop();
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> events = {{1,2}, {2,3}, {3,4}, {1,2}};
    cout << solution.maxEvents(events) << endl; // 4
}