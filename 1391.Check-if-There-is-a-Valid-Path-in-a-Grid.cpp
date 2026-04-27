#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return dfs(0, 0, grid, visited);
    }
private:
    vector<vector<pair<int,int>>> directions {
            {{0, -1}, {0, 1}}, // 1 left, right
            {{1, 0}, {-1, 0}}, // 2 down, up
            {{0, -1}, {1, 0}}, // 3 left, down
            {{1, 0}, {0, 1}}, // 4 down, right
            {{0, -1}, {-1, 0}}, // 5 left, up
            {{-1, 0}, {0, 1}}, // 6 up, right
    };
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        const int rows = grid.size(), cols = grid[0].size();

        if (visited[row][col]) return false;
        visited[row][col] = true;

        if (row == rows - 1 && col == cols - 1) return true;

        int type = grid[row][col] - 1;
        for (auto [dirRow, dirCol] : directions[type]) {
            int neighborRow = row + dirRow;
            int neighborCol = col + dirCol;
            if (neighborRow < 0 || neighborRow == rows ||
                neighborCol < 0 || neighborCol == cols ||
                visited[neighborRow][neighborCol]) {
                continue;
            }

            if (!isConnected(row, col, neighborRow, neighborCol, grid)) {
                continue;
            }

            if (dfs(neighborRow, neighborCol, grid, visited)) {
                return true;
            }
        }
        return false;      
    }
    bool isConnected(int row, int col, int neighborRow, int neighborCol, vector<vector<int>>& grid) {
        int dirRow = row - neighborRow;
        int dirCol = col - neighborCol;
        int type = grid[neighborRow][neighborCol] - 1;
        for (auto [neiDirRow, neiDirCol] : directions[type]) {
            if (dirRow == neiDirRow && dirCol == neiDirCol) {
                return true;
            }
        }   
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {2,4,3},
        {6,5,2}
    };
    cout << solution.hasValidPath(grid) << endl; // true
}
