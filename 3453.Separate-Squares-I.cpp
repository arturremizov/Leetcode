#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e9+1, high = 0;
        for (auto& square : squares) {
            double y = square[1], length = square[2];
            total += length * length;
            low = min(low, y);
            high = max(high, y + length);
        }

        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            if (areaBelow(mid, squares) < total / 2) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
private:
    double areaBelow(double height, vector<vector<int>>& squares) {
        double area = 0;
        for (auto& square : squares) {
            double y = square[1], length = square[2];
            if (y >= height) continue;
            if (y + length <= height) {
                area += length * length;
            } else {
                area += length * (height - y); 
            }
        }
        return area;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> squares = {{0,0,1}, {2,2,1}};
    cout << solution.separateSquares(squares) << endl; // 1.0
}