#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minX(n + 1, n);
        vector<int> minY(n + 1, n);
        vector<int> maxX(n + 1);
        vector<int> maxY(n + 1);
        for (auto& buiding : buildings) {
            int x = buiding[0], y = buiding[1];
            minX[y] = min(minX[y], x);
            minY[x] = min(minY[x], y);
            maxX[y] = max(maxX[y], x);
            maxY[x] = max(maxY[x], y);
        }
        int result = 0;
        for (auto& buiding : buildings) {
            int x = buiding[0], y = buiding[1];
            if (x > minX[y] && x < maxX[y] && y > minY[x] && y < maxY[x]) {
                ++result;
            }
        } 
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    cout << solution.countCoveredBuildings(3,buildings) << endl; // 1
}