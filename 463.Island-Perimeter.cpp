#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    set<pair<int, int>> visited;
                    return dfs(grid, visited, row, col);
                }
            }
        }
        return 0;
    }
private:
    int dfs(vector<vector<int>>& grid, set<pair<int, int>>& visited, int row, int col) {
        auto point = make_pair(row, col);
        if (visited.count(point)) {
            return 0;
        }
        if (row >= grid.size() || col >= grid[0].size() || 
            row < 0 || col < 0 || grid[row][col] == 0) {
            return 1;
        }
        visited.insert(point);
        int perimeter = dfs(grid, visited, row + 1, col);
        perimeter += dfs(grid, visited, row - 1, col);
        perimeter += dfs(grid, visited, row, col + 1);
        perimeter += dfs(grid, visited, row, col - 1);
        return perimeter;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    cout << solution.islandPerimeter(grid) << endl; // 16
}