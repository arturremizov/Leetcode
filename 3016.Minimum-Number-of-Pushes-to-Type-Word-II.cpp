#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26);
        for (char c : word) {
            counts[c - 'a']++;
        }

        sort(counts.begin(), counts.end(), greater<int>());

        int result = 0;
        int letters = 0;
        for (int count : counts) {
            result += count * (letters++ / 8 + 1);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumPushes("abcde") << endl; // 5
    cout << solution.minimumPushes("xyzxyzxyzxyz") << endl; // 12
    cout << solution.minimumPushes("aabbccddeeffgghhiiiiii") << endl; // 24
}