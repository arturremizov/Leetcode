#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    struct hashFunction {
        size_t operator()(const pair<int , int> &x) const {
            return x.first ^ x.second;
        }
    };
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int rows = grid1.size(), cols = grid1[0].size();
        unordered_set<pair<int, int>, hashFunction> visited;
        int result = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid2[row][col] && !visited.count({row, col}) &&
                    dfs(grid1, grid2, row, col, visited)) {
                    ++result;
                }
            }
        }
        return result;
    }
private:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, 
             int row, int col,
             unordered_set<pair<int, int>, hashFunction>& visited) {

        const int rows = grid1.size(), cols = grid1[0].size();

        if (row < 0 || col < 0 || row == rows || col == cols ||
            grid2[row][col] == 0 || visited.count({row, col})) {
            return true;
        }

        visited.insert({row, col});

        bool result = true;
        if (grid1[row][col] == 0) {
            result = false;
        }

        vector<pair<int, int>> neighbors = {
            {row - 1, col}, {row + 1, col},
            {row, col - 1}, {row, col + 1}
        };
        for (auto neighbor : neighbors) {
            if (!dfs(grid1, grid2, neighbor.first, neighbor.second, visited)) {
                result = false;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid1 = {
        {1,1,1,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,1,1}
    };
    vector<vector<int>> grid2 = {
        {1,1,1,0,0},
        {0,0,1,1,1},
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,1,0}
    };
    cout << solution.countSubIslands(grid1, grid2) << endl; // 3
}