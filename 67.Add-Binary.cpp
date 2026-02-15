#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        const int n = a.length(), m = b.length();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result = "";
        int cary = 0;
        for (int i = 0; i < max(n, m); ++i) {
            int digitA = i < n ? a[i] - '0' : 0;
            int digitB = i < m ? b[i] - '0' : 0;
            int value = (digitA + digitB + cary);
            cary = value / 2;
            result += ('0' + value % 2);
        }
        if (cary) {
            result += "1";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.addBinary("11","1") << endl; // "100"
}