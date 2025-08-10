#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n == 1) return true;
        string signature = sortDigits(n);
        int num = 1;
        while (num <= 1e9) {
            num *= 2;
            string powerSignature = sortDigits(num);
            if (signature == powerSignature) return true;
        }
        return false;
    }
private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution solution; 
    cout << solution.reorderedPowerOf2(10) << endl; // false
}