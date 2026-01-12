#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int result = 0;
        for (int i = 1; i < n; ++i) {
            int x1 = points[i - 1][0], y1 = points[i - 1][1];
            int x2 = points[i][0], y2 = points[i][1];
            result += max(abs(x2 - x1), abs(y2 - y1));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> points = {{1,1}, {3,4}, {-1,0}};
    cout << solution.minTimeToVisitAllPoints(points) << endl; // 7
}