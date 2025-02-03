#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
        unordered_map<int, int> islandSize;
        int islandLabel = 2;
        int result = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    int size = dfs(row,col,islandLabel,grid);
                    islandSize[islandLabel] = size;
                    ++islandLabel;
                    result = max(result, size);
                }
            }
        }

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    result = max(result, connect(row,col,grid,islandSize));   
                }
            }
        }
        return result;
    }
private:
    int dfs(int row, int col, int islandLabel, vector<vector<int>>& grid) {
        int islandSize = 1;
        grid[row][col] = islandLabel;

        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row - 1, col},
            {row, col + 1}, {row, col - 1}
        };
        const int n = grid.size();
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow < 0 || neighborCol < 0 || 
                neighborRow == n || neighborCol == n || 
                grid[neighborRow][neighborCol] != 1) {
                
                continue;
            }
            islandSize += dfs(neighborRow,neighborCol,islandLabel,grid);
        }
        return islandSize;
    }

    int connect(int row, int col, 
                vector<vector<int>>& grid, unordered_map<int, int>& islandSize) {

        int result = 1;
        unordered_set<int> visited;
        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row - 1, col},
            {row, col + 1}, {row, col - 1}
        };
        const int n = grid.size();
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow < 0 || neighborCol < 0 || 
                neighborRow == n || neighborCol == n ||
                grid[neighborRow][neighborCol] == 0 || 
                visited.count(grid[neighborRow][neighborCol])) {
                
                continue;
            }
            int islandLabel = grid[neighborRow][neighborCol];
            result += islandSize[islandLabel];
            visited.insert(islandLabel);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {1,0},
        {0,1}
    };
    cout << solution.largestIsland(grid) << endl; // 3
}