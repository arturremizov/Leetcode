#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<int> seen;
        int result = 0;
        for (char c : s) {
            if (seen.count(c)) {
                seen.erase(c);
                result += 2;
            } else {
                seen.insert(c);
            }
        }      
        return seen.size() > 0 ? result + 1 : result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.longestPalindrome("abccccdd") << endl; // 7
    cout << solution.longestPalindrome("a") << endl; // 1
};