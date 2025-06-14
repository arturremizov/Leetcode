#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string maxNum = to_string(num);
        int position = maxNum.find_first_not_of('9');
        if (position != string::npos) {
            char digit = maxNum[position];
            replace(maxNum.begin(), maxNum.end(), digit, '9');
        }

        string minNum = to_string(num);
        char digit = minNum[0];
        replace(minNum.begin(), minNum.end(), digit, '0');

        return stoi(maxNum) - stoi(minNum);
    }
};

int main() {
    Solution solution; 
    cout << solution.minMaxDifference(11891) << endl; // 99009
}