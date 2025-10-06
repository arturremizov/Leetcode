#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int time;
    int row;
    int col;

    bool operator<(Cell const &obj) const {
        return time < obj.time;
    }
    bool operator>(Cell const &obj) const {
        return time > obj.time;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<Cell, vector<Cell>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        while (!minHeap.empty()) {
            Cell cell = minHeap.top();
            minHeap.pop();

            if (cell.row == n - 1 && cell.col == n - 1) {
                return cell.time;
            }
            vector<pair<int, int>> neighbors {
                {cell.row - 1, cell.col}, {cell.row + 1, cell.col}, 
                {cell.row, cell.col - 1}, {cell.row, cell.col + 1}
            };
            for (auto [neiRow, neiCol] : neighbors) {
                if (neiRow < 0 || neiRow == n ||
                    neiCol < 0 || neiCol == n || 
                    visited[neiRow][neiCol]) {
                    continue;
                }
                int nextTime = max(cell.time, grid[neiRow][neiCol]);
                minHeap.push({nextTime, neiRow, neiCol});
                visited[neiRow][neiCol] = true;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    cout << solution.swimInWater(grid) << endl; // 16
}