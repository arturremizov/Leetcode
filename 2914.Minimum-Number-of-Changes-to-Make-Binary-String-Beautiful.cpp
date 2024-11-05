#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int result = 0;
        int i = 1;
        while (i < s.size()) {
            if (s[i-1] != s[i]) {
                ++result;
            } 
            i += 2;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.minChanges("1001") << endl; // 2
}