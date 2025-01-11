#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;
        
        unordered_map<char,int> charCount;
        for (char c : s) charCount[c]++;

        int odd = 0;
        for (auto [_, count] : charCount) {
            if (count % 2 == 1) {
                ++odd;
            }
        }
        return odd <= k;
    }
};

int main() {
    Solution solution; 
    cout << solution.canConstruct("annabelle", 2) << endl; // true
}