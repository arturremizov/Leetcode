#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        const int n = s.length();
        vector<string> parts;
        int count = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++count;
            } else {
                --count;
            }

            if (count == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string result;
        for (string &part : parts) {
            result += part;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.makeLargestSpecial("11011000") << endl; // "11100100"
}