#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int rows = grid.size(), cols = grid[0].size(), k = queries.size();
        vector<pair<int,int>> queriesWithIndex;
        for (int i = 0; i < k; ++i) {
            queriesWithIndex.push_back({queries[i], i});
        }
        sort(queriesWithIndex.begin(), queriesWithIndex.end());

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> minHeap;

        vector<vector<bool>> visited(rows, vector<bool>(cols));              
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int points = 0;
        vector<int> result(k);
        for (auto [limit, index]: queriesWithIndex) {
            while (!minHeap.empty() && get<0>(minHeap.top()) < limit) {
                auto [value, row, col] = minHeap.top();
                minHeap.pop();
                ++points;
                vector<pair<int, int>> neighbors = {
                    {row + 1, col}, {row - 1, col},
                    {row, col + 1}, {row, col - 1}
                };
                for (auto [neighborRow, neighborCol] : neighbors) {
                    if (neighborRow < 0 || neighborRow == rows ||
                        neighborCol < 0 || neighborCol == cols || 
                        visited[neighborRow][neighborCol]) {
                        continue;
                    }
    
                    visited[neighborRow][neighborCol] = true;
                    minHeap.push({grid[neighborRow][neighborCol], neighborRow, neighborCol});
                }
            }
            result[index] = points;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,2,3},
        {2,5,7},
        {3,5,1}
    };
    vector<int> queries = {5,6,2};
    vector<int> result = solution.maxPoints(grid, queries); //[5,8,1]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}