#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        set<pair<int, int>> visited;
        for (int row = 0; row < land.size(); ++row) {
            for (int col = 0; col < land[0].size(); ++col) {
                if (land[row][col] == 1 && !visited.count(make_pair(row, col))) {
                    result.push_back(bfs(land, row, col, visited));
                }            
            }  
        }
        return result;
    }
private:
    vector<int> bfs(vector<vector<int>>& land, int row, int col, set<pair<int, int>>& visited) {
        vector<int> result = {row, col};
        queue<pair<int, int>> queue;
        auto point = make_pair(row, col);
        queue.push(point);
        visited.insert(point);
        pair<int, int> currentPoint;
        while (!queue.empty()) {
            currentPoint = queue.front();
            queue.pop();
            vector<pair<int, int>> directions = { 
                make_pair(1, 0), make_pair(0, 1)
            };
            for (auto direction : directions) {
                int newRow = currentPoint.first + direction.first;
                int newCol = currentPoint.second + direction.second;
                auto newPoint = make_pair(newRow, newCol);
                if (newRow < land.size() && newCol < land[0].size() && 
                    land[newRow][newCol] == 1 && !visited.count(newPoint)) {
                        queue.push(newPoint);
                        visited.insert(newPoint);
                }
            }     
        }
        result.push_back(currentPoint.first);
        result.push_back(currentPoint.second);
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<vector<int>> land = {
        {1,0,0},
        {0,1,1},
        {0,1,1}
    };
    vector<vector<int>> result = solution.findFarmland(land);
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "] ";
    }
}