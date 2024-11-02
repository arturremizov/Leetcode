#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.front() != sentence.back()) return false;
        for (int i = 1; i < sentence.length() - 1; ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    cout << solution.isCircularSentence("leetcode exercises sound delightful") << endl; // true
}