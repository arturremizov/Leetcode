#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> charCount(26);
        for (char c : s) {
            charCount[c - 'a']++;
        }
        vector<char> candidates;
        for (int i = 25; i >= 0; --i) {
            if (charCount[i] < k) continue;
            candidates.push_back('a' + i);
        }

        queue<string> queue;
        for (char candidate : candidates) {
            queue.push(string(1, candidate));
        }   

        string result;
        while (!queue.empty()) {
            string current = queue.front();
            queue.pop();

            if (current.length() > result.length()) {
                result = current;
            }

            for (char candidate : candidates) {
                string next = current + candidate;
                if (isKRepeatedSubsequence(next, s, k)) {
                    queue.push(next);
                }
            }
        }
        return result;
    }
private:
    bool isKRepeatedSubsequence(const string subs, const string& s, const int k) {
        const int m = subs.length();
        int i = 0;
        int repeatedTotal = 0;
        for (char c : s) {
            if (c == subs[i]) {
                ++i;
                if (i == m) {
                    i = 0;
                    if (++repeatedTotal == k) return true;
                } 
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    cout << solution.longestSubsequenceRepeatedK("letsleetcode", 2) << endl; // let
}