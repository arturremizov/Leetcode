#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int negativeCount = 0;
        int minValue = INT32_MAX;
        for (auto row : matrix) {
            for (int num : row) {
                if (num < 0) {
                    ++negativeCount;
                }
                minValue = min(minValue, abs(num));
                result += abs(num);
            }
        }
        if (negativeCount % 2 == 1) {
            result -= (minValue * 2);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> matrix = {
        {1,2,3},
        {-1,-2,-3},
        {1,2,3}
    };
    cout << solution.maxMatrixSum(matrix) << endl; // 16
}