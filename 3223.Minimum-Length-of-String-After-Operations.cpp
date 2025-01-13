#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int result = s.length();
        vector<int> charCount(26);
        for (char c : s) {
            int charValue = c - 'a';
            charCount[charValue]++;
            if (charCount[charValue] == 3) {
                result -= 2;
                charCount[charValue] = 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumLength("abaacbcbb") << endl; // 5
}