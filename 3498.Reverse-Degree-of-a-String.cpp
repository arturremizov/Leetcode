#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reversedIndex = 26 - (s[i] - 'a');
            result += reversedIndex * (i + 1);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.reverseDegree("abc") << endl; // 148
}