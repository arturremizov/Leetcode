#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string result;
        char c = word[0];
        int count = 1;
        for (int i = 1; i < word.length(); i++) {
            if (c == word[i]) {
                if (count == 9) {
                    result += to_string(count);
                    result.push_back(c);
                    count = 1;
                } else {
                    ++count;
                }
            } else {
                result += to_string(count);
                result.push_back(c);
                c = word[i];
                count = 1;
            }
        }
        result += to_string(count);
        result.push_back(c);
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.compressedString("aaaaaaaaaaaaaabb") << endl; // 9a5a2b
}