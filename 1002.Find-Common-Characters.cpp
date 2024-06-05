#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> count;
        for (char c : words[0]) {
                count[c]++;
            }
        for (string word : words) {
            unordered_map<char, int> currentCount;
            for (char c : word) {
                currentCount[c]++;
            }
            for (const auto& [key, value] : count) {
                count[key] = min(value, currentCount[key]);
            }
        }
        vector<string> result;
        for (const auto& [key, value] : count) {
            for (int i = 0; i < value; ++i) {
                result.push_back({key});
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> words = {"bella","label","roller"};
    vector<string> result = solution.commonChars(words); // ["e","l","l"]
    for (string s : result) {
        cout << s << endl;
    }
}