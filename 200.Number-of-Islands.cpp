#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        set<pair<int, int>> visited;
        int islandsCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1' && !visited.count(make_pair(row, col))) {
                    ++islandsCount;
                    bfs(grid, row, col, visited);
                }
            }
        }
        return islandsCount;
    }
private:
    void bfs(vector<vector<char>>& grid, int row, int col, set<pair<int, int>>& visited) {
        queue<pair<int, int>> queue;
        auto point = make_pair(row, col);
        queue.push(point);
        visited.insert(point);
        while (!queue.empty()) {
            auto point = queue.front();
            queue.pop();
            vector<pair<int, int>> directions = { 
                make_pair(1, 0), make_pair(-1, 0),
                make_pair(0, 1), make_pair(0, -1)
            };
            for (auto direction : directions) {
                int newRow = point.first + direction.first;
                int newCol = point.second + direction.second;
                auto newPoint = make_pair(newRow, newCol);
                if (newRow >= 0 && newRow < grid.size() && 
                    newCol >= 0 && newCol < grid[0].size() && 
                    grid[newRow][newCol] == '1' && !visited.count(newPoint)) {
                        queue.push(newPoint);
                        visited.insert(newPoint);
                }
            }
        }
    }
};

int main() 
{
    Solution solution; 
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << solution.numIslands(grid) << endl; // 3
}