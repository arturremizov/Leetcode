#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int n = s.length();
        if (n - k <= 0) return false;
        unordered_set<string> codes;
        for (int i = 0; i < n - k + 1; ++i) {
            string code = s.substr(i, k);
            codes.insert(code);
        }
        return codes.size() == pow(2, k);
    }
};

int main() {
    Solution solution; 
    cout << solution.hasAllCodes("00110110", 2) << endl; // true
}