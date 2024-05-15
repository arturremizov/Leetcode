#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int n = grid.size();
        unordered_map<string, int> minDist = precompute(grid, n);

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        maxHeap.push({minDist[makeKey(0, 0)], {0, 0}});
        unordered_set<string> visited;
        visited.insert(makeKey(0, 0));
        
        while (!maxHeap.empty()) {
            int dist = maxHeap.top().first;
            auto point = maxHeap.top().second;
            maxHeap.pop();
            if (point.first == n - 1 && point.second == n - 1) {
                return dist;
            }
            vector<pair<int, int>> neighbors = getNeighbors(point.first, point.second);
            for (auto neighbor : neighbors) {
                int row = neighbor.first;
                int col = neighbor.second;
                string key = makeKey(row, col);
                if (inBounds(row, col, n) && !visited.count(key)) {
                    visited.insert(key);
                    int dist2 = min(dist, minDist[key]);
                    maxHeap.push({dist2, {row, col}});
                }
            }
        }
        return 0;
    }
private:
    unordered_map<string, int> precompute(vector<vector<int>>& grid, const int n) {
        queue<pair<pair<int, int>, int>> queue;
        unordered_map<string, int> minDist;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    queue.push({{row, col}, 0});
                    string key = makeKey(row, col);
                    minDist[key] = 0;
                }
            }
        }
        while (!queue.empty()) {
            auto point = queue.front().first;
            int dist = queue.front().second;
            queue.pop();
            vector<pair<int, int>> neighbors = getNeighbors(point.first, point.second);
            for (auto neighbor : neighbors) {
                int row = neighbor.first;
                int col = neighbor.second;
                string key = makeKey(row, col);
                if (inBounds(row, col, n) && !minDist.count(key)) {
                    minDist[key] = dist + 1;
                    queue.push({{row, col}, dist + 1});
                }
            } 
        }
        return minDist;
    }

    vector<pair<int, int>> getNeighbors(int row, int col) {
        return {
            {row + 1, col},
            {row - 1, col},
            {row, col + 1},
            {row, col - 1}
        };
    }

    string makeKey(int row, int col) {
        return to_string(row) + "," + to_string(col);
    }

    bool inBounds(int row, int col, int n) {
        return min(row, col) >= 0 && max(row, col) < n;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {0,0,1},
        {0,0,0},
        {0,0,0}
    };
    cout << solution.maximumSafenessFactor(grid) << endl; // 2
}