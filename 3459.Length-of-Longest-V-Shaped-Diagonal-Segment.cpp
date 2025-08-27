#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int result = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] != 1) continue;
                for (int i = 0; i < 4; ++i) {
                    result = max(result, 1 + dfs(row, col, 2, i, false, grid));
                }
            }
        }
        return result;
    }
private:
    vector<pair<int, int>> directions { {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    int dfs(int row, int col, int targetValue, int direction, bool isHasMadeTurn,
            vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int nextRow = row + directions[direction].first;
        int nextCol = col + directions[direction].second;
        if (nextRow < 0 || nextCol < 0 || nextRow == rows || nextCol == cols || 
            grid[nextRow][nextCol] != targetValue) return 0;
         
        int nextTarget = (targetValue == 2 ? 0 : 2);
        int result = 1 + dfs(nextRow, nextCol, nextTarget, direction, isHasMadeTurn, grid);
        if (!isHasMadeTurn) {
            int nextDirection = (direction + 1) % 4;
            result = max(result, 1 + dfs(nextRow, nextCol, nextTarget, nextDirection, true, grid));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {2,2,1,2,2}, 
        {2,0,2,2,0},
        {2,0,1,1,0},
        {1,0,2,2,2},
        {2,0,0,2,2}
    };
    cout << solution.lenOfVDiagonal(grid) << endl; // 5
}