#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        const int n = s.length();
        unordered_set<int> indicesToRemove;
        unordered_map<int,stack<int>> charToIndeces;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '*') {
                charToIndeces[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; ++j) {
                    if (charToIndeces[j].size() > 0) {
                        int index = charToIndeces[j].top();
                        charToIndeces[j].pop();
                        indicesToRemove.insert(index);
                        break;
                    }
                }
            }
        }
        string result;
        for (int i = 0; i < n; ++i) { 
            if (s[i] != '*' && !indicesToRemove.count(i)) {
                result += s[i];
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.clearStars("aaba*") << endl; // "aab"
}