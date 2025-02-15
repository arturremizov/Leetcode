#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (canPartition(0, 0, i, to_string(i * i))) {
                result += i * i;
            }
        }
        return result;
    }
private:
    bool canPartition(int i, int current, int target, string s) {
        if (i == s.length() && current == target) return true;

        for (int j = i; j < s.length(); ++j) {
            int part = stoi(s.substr(i, j - i + 1));
            if (canPartition(j + 1, current + part, target, s)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    cout << solution.punishmentNumber(10) << endl; // 182
}