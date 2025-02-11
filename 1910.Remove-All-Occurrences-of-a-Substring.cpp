#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for (char c : s) {
            result += c;
            if (hasSuffix(result, part)) {
                for (int i = 0; i < part.length(); ++i) {
                    result.pop_back();
                }
            }
        }
        return result;
    }
private:
    bool hasSuffix(string s, string suffix) {
        if (s.length() < suffix.length()) return false;

        for (int i = suffix.length() - 1; i >= 0; --i) {
            if (s.back() != suffix[i]) return false;
            s.pop_back();
        }
        return true;
    }
};

int main() {
    Solution solution; 
    cout << solution.removeOccurrences("daabcbaabcbc","abc") << endl; // "dab"
}