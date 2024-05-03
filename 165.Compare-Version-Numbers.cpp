#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            unsigned int num1 = 0, num2 = 0;
            while (i < n && version1[i] != '.') {
                num1 = (num1 * 10) + version1[i] - '0';
                ++i;
            }
            while (j < m && version2[j] != '.') {
                num2 = (num2 * 10) + version2[j] - '0';
                ++j;
            }
            if (num1 < num2) {
                return -1;
            } 
            if (num1 > num2) {
                return 1;
            } 
            ++i, ++j;
        }
        return 0;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.compareVersion("1.01", "1.001") << endl; // 0
    cout << solution.compareVersion("1.0", "1.0.0") << endl; // 0
    cout << solution.compareVersion("0.1", "1.1") << endl; // -1
}