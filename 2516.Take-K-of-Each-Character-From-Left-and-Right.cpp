#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        const int n = s.length();
        vector<int> count(3);
        for (char c : s) {
            count[c - 'a']++;
        }
        if (*min_element(count.begin(), count.end()) < k) {
            return -1;
        }
        int result = n;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']--;
            while (*min_element(count.begin(), count.end()) < k) {
                count[s[left] - 'a']++;
                ++left;
            }
            result = min(result, n - (right - left + 1));
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.takeCharacters("aabaaaacaabc", 2) << endl; // 8
}