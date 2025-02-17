#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> charCount;
        for (char c : tiles) charCount[c]++;
        return backtrack(charCount);
    }
private:
    int backtrack(unordered_map<char, int>& charCount) {
        int result = 0;
        for (auto [character, _] : charCount) {
            if (charCount[character] == 0) continue;
            charCount[character]--;
            result += 1 + backtrack(charCount);
            charCount[character]++;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numTilePossibilities("AAB") << endl; // 8
}