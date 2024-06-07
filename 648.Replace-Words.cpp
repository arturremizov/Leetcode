#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> set(dictionary.begin(), dictionary.end());

        istringstream iss(sentence);
        string word;
        string result;
        while (iss >> word) {
            string prefix = "";
            for (int i = 0; i < word.length(); ++i) {
                prefix += word[i];
                if (set.find(prefix) != set.end()) {
                    break;
                }
            }
            if (!result.empty()) {
                result += " ";
            }
            result += prefix;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << solution.replaceWords(dictionary, sentence) << endl; // "the cat was rat by the bat"
}