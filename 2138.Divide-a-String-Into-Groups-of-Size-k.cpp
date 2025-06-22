#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for (int i = 0; i < s.length(); i += k) {
            string group = s.substr(i, k);
            result.push_back(group);
        }
        int lastGroupLength = result.back().length();
        if (lastGroupLength < k) {
            string fillStr(k - lastGroupLength, fill);
            result.back().append(fillStr);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<string> result = solution.divideString("abcdefghij",3,'x'); //["abc","def","ghi","jxx"]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}