#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> remainingChars(26);
        for (char c : s) {
            remainingChars[c - 'a']++;
        }
        vector<bool> used(26);
        string result;
        for (char c : s) {
            int index = c - 'a';
            remainingChars[index]--;
            if (used[index]) continue;

            while (!result.empty() && 
                    result.back() > c && 
                    remainingChars[result.back() - 'a'] > 0) {
                
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(c);
            used[index] = true;
        } 
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.smallestSubsequence("bcabc") << endl; // "abc"
}