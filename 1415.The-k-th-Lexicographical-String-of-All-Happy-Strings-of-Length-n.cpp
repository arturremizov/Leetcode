#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        const int totalHappy = 3 * pow(2, n - 1);

        string result;
        string choices = "abc";
        int left = 1, right = totalHappy;

        for (int i = 0; i < n; ++i) {
            int current = left;
            int partitionSize = (right - left + 1) / choices.size();
            for (char c : choices) {
                if (k >= current && k < current + partitionSize) {
                    result += c;
                    left = current;
                    right = current + partitionSize - 1;
                    choices = (c == 'a') ? "bc" : (c == 'b') ? "ac" : "ab";
                    break;
                }
                current += partitionSize;
            } 
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.getHappyString(1,3) << endl; // "c"
}