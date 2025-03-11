#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.length();
        int left = 0;
        unordered_map<char, int> charCount;
        int result = 0;
        for (int right = 0; right < n; ++right) {
            charCount[s[right]]++;

            while (charCount.size() == 3) {
                result += n - right;
                charCount[s[left]]--;
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]);
                }
                ++left;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numberOfSubstrings("abcabc") << endl; // 10
}