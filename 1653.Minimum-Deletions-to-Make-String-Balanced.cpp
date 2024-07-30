#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int aCountRight = 0;
        for (char c : s) {
            if (c == 'a') {
                ++aCountRight;
            }
        }

        int bCountLeft = 0;
        int result = s.length();
        for (char c : s) {
            if (c == 'a') {
                --aCountRight;
            }
            int deletions = bCountLeft + aCountRight;
            result = min(result, deletions);
            if (c == 'b') {
                ++bCountLeft;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.minimumDeletions("aababbab") << endl; // 2
    cout << solution.minimumDeletions("bbaaaaabb") << endl; // 2
}