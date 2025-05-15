#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            if (i == 0 || groups[i - 1] != groups[i]) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"e","a","b"};
    vector<int> groups = {0,0,1};
    vector<string> result = solution.getLongestSubsequence(words, groups); // ["e","b"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}