#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = cells.size();
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canCross(mid,row,col,cells)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
private:
    bool canCross(int day, int rows, int cols, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows, vector<int>(cols));
        for (int i = 0; i < day; ++i) {
            int row = cells[i][0] - 1, col = cells[i][1] - 1;
            grid[row][col] = 1; // mark as water
        }
        
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int col = 0; col < cols; ++col) {
            if (grid[0][col] == 1) continue;
            visited[0][col] = true;
            if (dfs(0, col, grid, visited)) {
                return true;
            }
        }
        return false;
    }

    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        const int rows = grid.size(), cols = grid[0].size();
        if (row == rows - 1) return true;

        vector<pair<int, int>> neighbors = {
            {row + 1, col}, {row - 1, col},
            {row, col + 1}, {row, col - 1}
        };
        for (auto [neighborRow, neighborCol] : neighbors) {
            if (neighborRow < 0 || neighborCol < 0 || neighborCol >= cols ||
                visited[neighborRow][neighborCol] ||
                grid[neighborRow][neighborCol] == 1) continue;

            visited[neighborRow][neighborCol] = true;
            if (dfs(neighborRow, neighborCol, grid, visited)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> cells = {{1,1},{2,1},{1,2},{2,2}};
    cout << solution.latestDayToCross(2,2,cells) << endl; // 2
}