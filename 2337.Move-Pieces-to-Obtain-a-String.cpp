#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        const int n = start.length();
        queue<pair<char, int>> startQueue, targetQueue;
        for (int i = 0; i < n; ++i) {
            if (start[i] != '_') {
                startQueue.push({start[i], i});
            }
            if (target[i] != '_') {
                targetQueue.push({target[i], i});
            }
        }

        if (startQueue.size() != targetQueue.size()) return false;

        while (!startQueue.empty()) {
            auto [startChar, startIndex] = startQueue.front();
            startQueue.pop();
            auto [targetChar, targetIndex] = targetQueue.front();
            targetQueue.pop();

            if (startChar != targetChar || 
                (startChar == 'L' && startIndex < targetIndex) || 
                (startChar == 'R' && startIndex > targetIndex)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    cout << solution.canChange("_L__R__R_", "L______RR") << endl; // true
}