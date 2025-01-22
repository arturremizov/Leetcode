#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int rows = isWater.size(), cols = isWater[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, -1));
        queue<pair<int, int>> queue;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (isWater[row][col] == 1) {
                    queue.push({row, col});
                    result[row][col] = 0;
                }
            }
        }
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            int height = result[row][col];

            vector<pair<int, int>> neighbors = {
                {row + 1, col}, {row - 1, col},
                {row, col + 1}, {row, col - 1}
            };
            for (auto [neighborRow, neighborCol] : neighbors) {
                if (neighborRow < 0 || neighborCol < 0 || 
                    neighborRow == rows || neighborCol == cols || 
                    result[neighborRow][neighborCol] != -1) {
                    
                    continue;
                }

                queue.push({neighborRow, neighborCol});
                result[neighborRow][neighborCol] = height + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> isWater = {
        {0,1},
        {0,0}
    }; 
    vector<vector<int>> result = solution.highestPeak(isWater); // [[1,0],[2,1]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}