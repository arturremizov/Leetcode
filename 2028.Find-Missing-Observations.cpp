#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        int totalSum = mean * (m + n);

        int rollSum = 0;
        for (int roll : rolls) { rollSum += roll; }
        int missingSum = totalSum - rollSum;

        if (missingSum > 6 * n || missingSum < n) return {};

        int missingMean = missingSum / n;
        vector<int> result(n, missingMean);
        int remainder = missingSum % n;
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> rolls = {3,2,4,3};
    vector<int> result = solution.missingRolls(rolls, 4, 2); // [6,6]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}