#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int left = 0;
        long long result = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (s[right] == '0') {
                result += right - left;
                ++left;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumSteps("101") << endl; // 1
}