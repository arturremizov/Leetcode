#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.length();
        vector<int> nextZero(n, n);
        for (int i = n - 2; i >= 0; --i) {
            if (s[i + 1] == '0') {
                nextZero[i] = i + 1;
            } else {
                nextZero[i] = nextZero[i + 1];
            }
        }

        int result = 0;
        for (int left = 0; left < n; ++left) {
            int zeroes = s[left] == '0' ? 1 : 0;
            int right = left;
            while (zeroes * zeroes <= n) {
                int nextZeroIndex = nextZero[right];
                int ones = (nextZeroIndex - left) - zeroes;
                if (ones >= zeroes * zeroes) {
                    result += min(nextZeroIndex - right, ones - zeroes * zeroes + 1);
                }
                right = nextZeroIndex;
                ++zeroes;
                if (right == n) break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numberOfSubstrings("101101") << endl; //16
}
