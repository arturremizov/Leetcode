#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    struct CharInfo {
        int firstIndex = -1;
        int lastIndex = -1;
        int count = 0;
    };
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int n = s.length();
        vector<CharInfo> charInfo(26);
        vector<int> order;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (charInfo[c].count == 0) {
                charInfo[c].firstIndex = i;
                order.push_back(c);
            }
            charInfo[c].count++;
            charInfo[c].lastIndex = i;
        }

        vector<string> result;
        vector<CharInfo> pending;
        for (int c : order) {
            pending.push_back(charInfo[c]);
            int total = 0;
            int left = n;
            int right = -1;
            for (int i = pending.size() - 1; i >=0; --i) {
                total += pending[i].count;
                left = min(left, pending[i].firstIndex);
                right = max(right, pending[i].lastIndex);
                if (total == right - left + 1) {
                    result.push_back(s.substr(left, total));
                    pending.clear();
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> result = solution.maxNumOfSubstrings("adefaddaccc"); // ["e","f","ccc"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}