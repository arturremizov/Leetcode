#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        const int n = s.length();
        // char : {substr length : substr count}
        unordered_map<char, unordered_map<int, int>> count; 
        for (int i = 0; i < n; ++i) {
            int currentLength = 0;
            for (int j = i; j < n; ++j) {
                if (s[i] != s[j]) break;
                count[s[i]][++currentLength]++;
             }
        }
        int result = -1;
        for (auto [_, substrMap] : count) {
            for (auto [substrLength, substrCount] : substrMap) {
                if (substrCount < 3) continue;
                result = max(result, substrLength);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.maximumLength("aaaa") << endl; // 2
}