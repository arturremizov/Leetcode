#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> countMap;

        string word;
        stringstream stream(s1 + " " + s2);
        while (stream >> word) {
            countMap[word]++;
        }

        vector<string> result;
        for (auto& [word, count] : countMap) {
            if (count == 1) {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> result = solution.uncommonFromSentences("this apple is sweet","this apple is sour"); // ["sweet","sour"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}