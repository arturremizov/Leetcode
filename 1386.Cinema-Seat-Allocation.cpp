#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int seats1 = 0b00001111;
        int seats2 = 0b11000011;
        int seats3 = 0b11110000;
        unordered_map<int, int> reserved;
        for (auto& reservedSeat : reservedSeats) {
            int row = reservedSeat[0], seat = reservedSeat[1];
            if (seat == 1 || seat == 10) continue;
            reserved[row] |= (1 << (seat - 2)); 
        }
        int result = (n - reserved.size()) * 2;
        for (auto [_, seats] : reserved) {
            if (((seats | seats1) == seats1) ||
                ((seats | seats2) == seats2) || 
                ((seats | seats3) == seats3)) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    cout << solution.maxNumberOfFamilies(3, reservedSeats) << endl; // 4
}