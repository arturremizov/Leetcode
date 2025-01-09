#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        for (string word : words) {
            if (word.find(pref) == 0) {
                ++result;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"pay","attention","practice","attend"};
    cout << solution.prefixCount(words, "at") << endl; // 2
}