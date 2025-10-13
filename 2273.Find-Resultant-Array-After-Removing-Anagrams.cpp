#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        const int n = words.size();
        vector<string> result { words[0] };
        string prevWord = words[0];
        sort(prevWord.begin(), prevWord.end());
        for (int i = 1; i < n; ++i) {
            string word = words[i];
            sort(word.begin(), word.end());
            if (prevWord != word) {
                result.push_back(words[i]);
                prevWord = word;
            }
        }   
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    vector<string> result = solution.removeAnagrams(words); // ["abba","cd"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}