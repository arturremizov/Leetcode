#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.length();
        queue<int> queue;
        queue.push(0);
        int farthest = 0;
        while (!queue.empty()) {
            int i = queue.front();
            queue.pop();
            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);
            for (int j = start; j <= end; ++j) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    queue.push(j);
                }
            }
            farthest = end;
        }
        return false;
    }
};

int main() {
    Solution solution; 
    cout << solution.canReach("011010", 2, 3) << endl; // true
}