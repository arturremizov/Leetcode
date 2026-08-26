#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string result = "";
        int currK = 0;
        int currLength = 101;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (s[right] == '1') ++currK;
            while (currK > k || s[left] == '0') {
                if (s[left] == '1') --currK;
                ++left;
            }
            if (currK == k) {
                int length = right - left + 1;
                if (length < currLength) {
                    result = s.substr(left, length);
                    currLength = length;
                } else if (length == currLength) {
                    result = min(result, s.substr(left, length));
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.shortestBeautifulSubstring("100011001", 3) << endl; // "11001"
}