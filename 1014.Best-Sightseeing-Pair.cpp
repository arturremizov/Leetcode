#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n = values.size();
        int result = 0;
        int currentMax = values[0] - 1;
        for (int i = 1; i < n; ++i) {
            result = max(result, values[i] + currentMax);
            currentMax = max(currentMax - 1, values[i] - 1);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> values = {8,1,5,2,6};
    cout << solution.maxScoreSightseeingPair(values) << endl; // 11
}