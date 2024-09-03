#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int number = 0;
        for (char c : s) {
            int n = c - 'a' + 1;
            while (n > 0) {
                number += n % 10;
                n /= 10;
            }
        }
        
        for (int i = 1; i < k; i++) {
            int n = number;
            number = 0;
            while (n > 0) {
                number += n % 10;
                n /= 10;
            }
        }   
        return number;
    }
};

int main() {
    Solution solution; 
    cout << solution.getLucky("leetcode", 2) << endl; // 6
}