#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int n = points.size();
        sort(points.begin(), points.end(), [] (auto& lhs, auto& rhs) {
            if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        });
        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (points[i][1] < points[j][1]) continue;
                bool isValid = true;
                for (int k = i + 1; k < j; ++k) {
                    if (points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> points = {{6,2},{4,4},{2,6}};
    cout << solution.numberOfPairs(points) << endl; // 2
}