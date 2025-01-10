#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> count2;
        for (string word : words2) {
            unordered_map<char, int> wordCount;
            for (char c : word) wordCount[c]++;

            for (auto [c, count] : wordCount) {
                count2[c] = max(count2[c], count);
            }
        }

        vector<string> result;
        for (string word : words1) {
            unordered_map<char, int> wordCount;
            for (char c : word) wordCount[c]++;

            bool isSubSet = true;
            for (auto [c, count] : count2) {
                if (wordCount[c] < count) {
                    isSubSet = false;
                    break;
                }
            }

            if (isSubSet) {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    vector<string> result = solution.wordSubsets(words1,words2); //["facebook","google","leetcode"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}