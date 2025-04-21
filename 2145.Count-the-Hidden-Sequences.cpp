#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minValue = 0;
        long long maxValue = 0;
        long long current = 0;
        for (int difference : differences) {
            current += difference;
            minValue = min(minValue, current);
            maxValue = max(maxValue, current);
        }
        int currentRange = maxValue - minValue;
        int possibleRange = upper - lower;
        if (possibleRange < currentRange) return 0;
        return possibleRange - currentRange + 1;
    }
};

int main() {
    Solution solution; 
    vector<int> differences = {1,-3,4};
    cout << solution.numberOfArrays(differences, 1, 6) << endl; // 2
}
