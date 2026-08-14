#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26);
        int result = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            int index = s[right] - 'a';
            freq[index]++;
            while (freq[index] > 2) {
                freq[s[left] - 'a']--;
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.maximumLengthSubstring("bcbbbcba") << endl; // 4
}