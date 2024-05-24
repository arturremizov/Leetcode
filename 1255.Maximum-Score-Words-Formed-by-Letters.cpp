#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letterCount;
        for (char c : letters) {
            letterCount[c]++;
        }
        return backtrack(words, letterCount, score, 0);
    }
private:
    int backtrack(vector<string>& words, unordered_map<char, int>& letterCount, vector<int>& score, int i) {
        if (i == words.size()) return 0;
        int result = backtrack(words, letterCount, score, i + 1); // skip word
        if (canFormWord(words[i], letterCount)) {
            int wordScore = 0;
            for (char c : words[i]) {
                letterCount[c]--;

                int letterIndex = c - 'a';
                wordScore += score[letterIndex];
            }
            result = max(result, wordScore + backtrack(words, letterCount, score, i + 1)); // include word
            for (char c : words[i]) {
                letterCount[c]++;
            }
        }
        return result;
    }
    bool canFormWord(string word, unordered_map<char, int>& letterCount) {
        unordered_map<char, int> wordLetterCount;
        for (char c : word) {
            wordLetterCount[c]++;
        }
        for (char c : word) {
            if (wordLetterCount[c] > letterCount[c]) {
                return false;
            }
        }
        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout << solution.maxScoreWords(words, letters, score) << endl; // 23
}