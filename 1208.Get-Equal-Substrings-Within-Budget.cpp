#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.length();
        int currentCost = 0, maxLength = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            currentCost += abs(s[right] - t[right]);
            while (currentCost > maxCost && left <= right) {
                currentCost -= abs(s[left] - t[left]);
                ++left;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.equalSubstring("abcd", "bcdf", 3) << endl; // 3
    cout << solution.equalSubstring("abcd", "cdef", 3) << endl; // 1
    cout << solution.equalSubstring("abcd", "acde", 0) << endl; // 1
}