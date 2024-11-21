#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        // 0 - free, 1 - guard, 2 = wall, 3 = guardable
        for (auto guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }

        for (auto guard : guards) {
            markGuarded(grid, guard[0], guard[1], m, n);
        }
        int result = 0;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    ++result;
                }
            }
        }

        return result;
    }
private:
    void markGuarded(vector<vector<int>>& grid, int r, int c, int m, int n) {
        for (int row = r + 1; row < m; ++row) {
            if (grid[row][c] == 2 || grid[row][c] == 1) break;
            grid[row][c] = 3;
        }
        for (int row = r - 1; row >= 0; --row) {
            if (grid[row][c] == 2 || grid[row][c] == 1) break;
            grid[row][c] = 3;
        }
        for (int col = c + 1; col < n; ++col) {
            if (grid[r][col] == 2 || grid[r][col] == 1) break;
            grid[r][col] = 3;
        }
        for (int col = c - 1; col >= 0; --col) {
            if (grid[r][col] == 2 || grid[r][col] == 1) break;
            grid[r][col] = 3;
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    cout << solution.countUnguarded(4,6,guards,walls) << endl; // 7
}