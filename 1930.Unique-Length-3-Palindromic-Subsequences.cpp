#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<int> left;
        unordered_map<char, int> right;
        for (char c : s) right[c]++;

        unordered_set<string> result;
        for (char mid : s) {
            right[mid]--;
            for (char c : left) {
                if (right[c] > 0) {
                    result.insert({mid, c});
                }
            }
            left.insert(mid);
        }
        return result.size();
    }
};

int main() {
    Solution solution; 
    cout << solution.countPalindromicSubsequence("aabca") << endl; // 3
}