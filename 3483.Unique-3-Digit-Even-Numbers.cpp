#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int num : digits) {
            freq[num]++;
        }
        int result = 0;
        for (int num = 100; num < 999; num += 2) {
            int hundreds = num / 100 % 10;
            int tens = num / 10 % 10;
            int ones = num % 10;
            freq[hundreds]--;
            freq[tens]--;
            freq[ones]--;
            if (freq[hundreds] >= 0 && freq[tens] >= 0 && freq[ones] >= 0) {
                ++result;
            }   
            freq[hundreds]++;
            freq[tens]++;
            freq[ones]++;        
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> digits = {1,2,3,4};
    cout << solution.totalNumbers(digits) << endl; // 12
}