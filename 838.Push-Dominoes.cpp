#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        const int n = dominoes.length();
        vector<int> forces(n);
        int force = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                force = n;
            } else if (dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(0, force - 1);
            }
            forces[i] += force;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                force = n;
            } else if (dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(0, force - 1);
            }
            forces[i] -= force;
        }

        string result;
        for (int i = 0; i < n; ++i) {
            if (forces[i] > 0) {
                result.append("R");
            } else if (forces[i] < 0) {
                result.append("L");
            } else {
                result.append(".");
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.pushDominoes(".L.R...LR..L..") << endl; // LL.RR.LLRRLL..
}
 