#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        int maxOddCount = 0;
        int minEvenCount = s.length();
        for (auto [_, count] : charCount) {
            if (count % 2 == 1) {
                maxOddCount = max(maxOddCount, count);
            } else {
                minEvenCount = min(minEvenCount, count);
            }
        }
        return maxOddCount - minEvenCount;
    }
};

int main() {
    Solution solution; 
    cout << solution.maxDifference("aaaaabbc") << endl; // 3
}