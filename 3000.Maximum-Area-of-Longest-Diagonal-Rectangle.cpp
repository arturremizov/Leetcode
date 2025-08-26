#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        double maxDiagonal = 0;
        for (vector<int>& dimension : dimensions) {
            int length = dimension[0], width = dimension[1];
            double diagonal = sqrt(length * length + width * width);
            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                result = length * width;
            } else if (diagonal == maxDiagonal) {
                result = max(result, length * width);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> dimensions = {{9,3}, {8,6}};
    cout << solution.areaOfMaxDiagonal(dimensions) << endl; // 48
}