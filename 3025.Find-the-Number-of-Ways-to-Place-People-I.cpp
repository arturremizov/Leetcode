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
            int a_y = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int b_y = points[j][1];
                if (a_y >= b_y) {
                    bool isValid = true;
                    for (int k = i + 1; k < j; ++k) {
                        int c_y = points[k][1];
                        if (a_y >= c_y && c_y >= b_y) {
                            isValid = false;
                            break;
                        };
                    }
                    if (isValid) ++result;
                }
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