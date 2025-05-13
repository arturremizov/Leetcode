#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9+7;
        vector<int> freq(26);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < t; ++i) {
            vector<int> next(26);
            next[0] = freq[25];
            next[1] = (freq[0] + freq[25]) % MOD;
            for (int i = 2; i < 26; ++i) {
                next[i] = freq[i - 1];
            }
            freq = next;
        }
        int result = 0;
        for (int count : freq) {
            result = (result + count) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.lengthAfterTransformations("abcyy", 2) << endl; // 7
}
 