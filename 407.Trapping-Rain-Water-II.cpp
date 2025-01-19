#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int rows = heightMap.size(), cols = heightMap[0].size();

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> minHeap;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {

                    minHeap.push({heightMap[row][col], row, col});
                    heightMap[row][col] = -1; // visited
                }
            }
        }

        int result = 0;
        int maxHeight = 0;

        while (!minHeap.empty()) {
            auto [height, row, col] = minHeap.top();
            minHeap.pop();

            maxHeight = max(maxHeight, height);
            result += maxHeight - height;

            vector<pair<int, int>> neighbors = {
                {row + 1, col}, {row - 1, col},
                {row, col + 1}, {row, col - 1}
            };
            for (auto [neighborRow, neighborCol] : neighbors) {
                if (neighborRow < 0 || neighborCol < 0 || 
                    neighborRow == rows || neighborCol == cols ||
                    heightMap[neighborRow][neighborCol] == -1) {
                        continue;
                }
                minHeap.push({heightMap[neighborRow][neighborCol], neighborRow, neighborCol});
                heightMap[neighborRow][neighborCol] = -1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    }; 
    cout << solution.trapRainWater(heightMap) << endl; // 4
}