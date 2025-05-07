#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> minHeap; 

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        minHeap.push({0, 0, 0}); // curr time, row, col
        visited[0][0] = true;
        while (!minHeap.empty()) {
            auto [currTime, row, col] = minHeap.top();
            minHeap.pop();
            if (row == n - 1 && col == m - 1) return currTime;
            
            vector<pair<int, int>> neighbors {
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
                int time = max(currTime, moveTime[neighborRow][neighborCol]);
                minHeap.push({time + 1, neighborRow, neighborCol});
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
    cout << solution.minTimeToReach(moveTime) << endl; // 6
}
 