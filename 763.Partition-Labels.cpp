#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = s.length();
        unordered_map<char, int> charLastIndex;
        for (int i = 0; i < n; ++i) {
            charLastIndex[s[i]] = i;
        }

        vector<int> result;
        int end = 0;
        int currentSize = 0;
        for (int i = 0; i < n; ++i) {
            ++currentSize;
            end = max(end, charLastIndex[s[i]]);
            if (end == i) {
                result.push_back(currentSize);
                currentSize = 0;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> result = solution.partitionLabels("ababcbacadefegdehijhklij"); //[9,7,8]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}