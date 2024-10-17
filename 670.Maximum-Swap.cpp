#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        const int n = numStr.length();
        char maxDigit = '0';
        int max_i = -1;
        int swap_i = -1, swap_j = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (numStr[i] > maxDigit) {
                maxDigit = numStr[i];
                max_i = i;
            }
            
            if (numStr[i] < maxDigit) {
                swap_i = i;
                swap_j = max_i;
            }
        }
        if (swap_i != -1) {
            swap(numStr[swap_i], numStr[swap_j]);
        }
        return stoi(numStr);
    }
};

int main() {
    Solution solution; 
    cout << solution.maximumSwap(2736) << endl; // 7236
}