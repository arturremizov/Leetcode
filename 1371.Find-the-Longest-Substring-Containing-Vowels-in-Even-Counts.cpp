#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int result = 0;
        int mask = 0;
        unordered_map<int,int> masksToIndex = {{0,-1}};
        for (int i = 0; i < s.length(); i++) {
            if (vowels.count(s[i])) {
                mask = mask ^ (1 + s[i] - 'a');
            }
            if (masksToIndex.count(mask)) {
                int length = i - masksToIndex[mask];
                result = max(result, length);
            } else {
                masksToIndex[mask] = i;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.findTheLongestSubstring("eleetminicoworoep") << endl; // 13
    cout << solution.findTheLongestSubstring("leetcodeisgreat") << endl; // 5
    cout << solution.findTheLongestSubstring("bcbcbc") << endl; // 6
}