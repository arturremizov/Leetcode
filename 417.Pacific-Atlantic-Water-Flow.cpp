#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        for (int col = 0; col < cols; ++col) {
            dfs(0, col, pacific, heights[0][col], heights);
            dfs(rows - 1, col, atlantic, heights[rows - 1][col], heights);
        }

        for (int row = 0; row < rows; ++row) {
            dfs(row, 0, pacific, heights[row][0], heights);
            dfs(row, cols - 1, atlantic, heights[row][cols - 1], heights);
        }

        vector<vector<int>> result;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) { 
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }
        return result;
    }
private:
    void dfs(int row, int col, 
             vector<vector<bool>>& visited,
             int prevHeight,
             vector<vector<int>>& heights) {
        
        const int rows = heights.size(), cols = heights[0].size();
        if (row < 0 || row == rows || 
            col < 0 || col == cols || 
            visited[row][col] || 
            heights[row][col] < prevHeight) {
            return;
        }   
        
        visited[row][col] = true;
        vector<pair<int, int>> neighbors {
            {row + 1, col},  {row - 1, col},
            {row, col + 1},  {row, col - 1}
        };
        for (auto [neiRow, neiCol] : neighbors) {
            dfs(neiRow, neiCol, visited, heights[row][col], heights);
        }
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    vector<vector<int>> result = solution.pacificAtlantic(heights); // [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}