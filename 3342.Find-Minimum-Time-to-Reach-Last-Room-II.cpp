#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<tuple<int, bool, int, int>,
                       vector<tuple<int, bool, int, int>>,
                       greater<tuple<int, bool, int, int>>> minHeap;

        vector<vector<int>> visited(n, vector<int>(m));
        minHeap.push({0, false, 0, 0});
        visited[0][0] = true;
        while (!minHeap.empty()) {
            auto [currTime, isNextTwoSec, row, col] = minHeap.top();
            minHeap.pop();
            
            if (row == n - 1 && col == m - 1) return currTime;
            vector<pair<int, int>> neighbors = {
                {row + 1, col}, {row - 1, col},
                {row, col + 1}, {row, col - 1}
            };
            for (auto [neighborRow, neighborCol] : neighbors) {
                if (neighborRow < 0 || neighborRow >= n || 
                    neighborCol < 0 || neighborCol >= m || 
                    visited[neighborRow][neighborCol]) {
                    continue;
                }
                visited[neighborRow][neighborCol] = true;
                int nextTime = max(currTime, moveTime[neighborRow][neighborCol]);
                nextTime += isNextTwoSec ? 2 : 1;
                minHeap.push({nextTime , !isNextTwoSec, neighborRow, neighborCol});
            }
        }
        return 0;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> moveTime = {
        {0,4},
        {4,4}
    };
    cout << solution.minTimeToReach(moveTime) << endl; // 7
}
 