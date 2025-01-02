#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int n = words.size();
        const int m = queries.size();

        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};

        vector<int> prefixCount(n + 1);
        for (int i = 0; i < n; ++i) {
            int isVowel = 0;
            if (vowelSet.count(words[i].front()) && vowelSet.count(words[i].back())) {
                isVowel = 1;
            }
            prefixCount[i + 1] = prefixCount[i] + isVowel;
        }

        vector<int> result(m);
        for (int i = 0; i < m; ++i) {
            int left = queries[i][0];
            int right = queries[i][1];
            result[i] = prefixCount[right + 1] - prefixCount[left];
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> result = solution.vowelStrings(words, queries); //[2,3,0]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}