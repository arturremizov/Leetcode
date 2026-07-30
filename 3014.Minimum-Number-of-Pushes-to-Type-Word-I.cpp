#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int letters = word.length();
        if (letters <= 8) return letters;
        if (letters <= 16) return 8 + (letters - 8) * 2;
        if (letters <= 24) return 8 + 16 + (letters - 16) * 3;
        return 8 + 16 + 24 + (letters - 24) * 4;
    }
};

int main() {
    Solution solution; 
    cout << solution.minimumPushes("xycdefghij") << endl; // 12
}