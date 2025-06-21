#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for (char c : word) {
            freq[c - 'a']++;
        }

        vector<int> counts;
        for (int f : freq) {
            if (f == 0) continue;
            counts.push_back(f);
        }
        
        int result = word.length();
        int maxFreq = *max_element(counts.begin(), counts.end());
        for (int curFreq = 1; curFreq <= maxFreq; ++curFreq) {
            int deletions = 0;
            for (int charCount : counts) {
                if (charCount < curFreq) {
                    deletions += charCount;
                } else if (charCount > curFreq + k) {
                    deletions += charCount - (curFreq + k);
                }
            }
            result = min(result, deletions);
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.minimumDeletions("aabcaba", 0) << endl; // 3
}