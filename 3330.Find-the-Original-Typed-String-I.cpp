#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i - 1] == word[i]) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.possibleStringCount("abbcccc") << endl; // 5
}