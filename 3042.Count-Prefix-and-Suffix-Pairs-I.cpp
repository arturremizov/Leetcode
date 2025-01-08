#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++result;
                }
            }
        }
        return result;
    }
private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        if (str1.length() > str2.length()) return false;
        return str2.find(str1) == 0 && str2.rfind(str1) == str2.length() - str1.length();
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"a","aba","ababa","aa"};
    cout << solution.countPrefixSuffixPairs(words) << endl; // 4
}