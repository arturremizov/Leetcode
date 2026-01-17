#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int n = bottomLeft.size();
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right = min(topRight[i][0], topRight[j][0]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top = min(topRight[i][1], topRight[j][1]);

                int width = right - left;
                int height = top - bottom;
                if (width > 0 && height > 0) {
                    long long size = min(width, height);
                    result = max(result, size * size);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> bottomLeft = {{1,1}, {2,2}, {3,1}};
    vector<vector<int>> topRight = {{3,3}, {4,4}, {6,6}};
    cout << solution.largestSquareArea(bottomLeft, topRight) << endl; // 1
}