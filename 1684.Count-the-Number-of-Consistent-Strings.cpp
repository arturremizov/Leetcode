#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bitMask = 0;
        for (char c : allowed) {
            int bit = 1 << c - 'a';
            bitMask = bitMask | bit;
        }

        int result = words.size();
        for (string word : words) {
            for (char c : word) {
                int bit = 1 << c - 'a';
                if ((bit & bitMask) == 0) {
                    --result;
                    break;
                } 
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    cout << solution.countConsistentStrings("ab", words) << endl; // 2
}