#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>   
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowercaseWords;
        unordered_map<string, string> noVowelsWords;
        for (string word : wordlist) {
            string low = lowercase(word);
            if (!lowercaseWords.count(low)) {
                lowercaseWords[low] = word;
            }
            string noVowels = eraseVowels(low);
            if (!noVowelsWords.count(noVowels)) {
                noVowelsWords[noVowels] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            if (words.count(query)) {
                result.push_back(query);
                continue;
            } 
            
            string lowQuery = lowercase(query);
            if (lowercaseWords.count(lowQuery)) {
                result.push_back(lowercaseWords[lowQuery]);
                continue;
            }

            string noVowelsQuery = eraseVowels(lowQuery);
            if (noVowelsWords.count(noVowelsQuery)) {
                result.push_back(noVowelsWords[noVowelsQuery]);
                continue;
            }

            result.push_back("");
        }
        return result;
    }
private:
    string lowercase(string s) {
        for (char& c : s) {
            c = tolower(c);
        }
        return s;
    }
    string eraseVowels(string s) {
        string result = s;
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                result[i] = '*';
            }
        }
        return result;
    }
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    Solution solution; 
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> result = solution.spellchecker(wordlist, queries); // ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}