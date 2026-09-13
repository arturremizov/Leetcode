#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        int result = 0;
        for (int rowOffset = -n + 1; rowOffset < n; ++rowOffset) {
            for (int colOffset = -n + 1; colOffset < n; ++colOffset) {
                int curResult = 0;
                for (int row = 0; row < n; ++row) {
                    for (int col = 0; col < n; ++col) {
                        if (img1[row][col] == 0) continue;
                        int newRow = row + rowOffset;
                        int newCol = col + colOffset;
                        if (newRow >= 0 && newCol >= 0 && 
                            newRow < n && newCol < n &&
                            img2[newRow][newCol] == 1) {
                            ++curResult;
                        }
                    }
                }
                result = max(result, curResult);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> img1 = {
        {1,1,0},
        {0,1,0},
        {0,1,0}
    };
    vector<vector<int>> img2 = {
        {0,0,0},
        {0,1,1},
        {0,0,1}
    };
    cout << solution.largestOverlap(img1, img2) << endl; // 3
}