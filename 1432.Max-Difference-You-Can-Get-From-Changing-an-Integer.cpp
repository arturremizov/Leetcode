#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string maxNum = to_string(num);
        int position = maxNum.find_first_not_of('9');
        if (position != string::npos) {
            char x = maxNum[position];
            replace(maxNum.begin(), maxNum.end(), x, '9');
        }

        string minNum = to_string(num);
        if (minNum[0] != '1') {
            char x = minNum[0];
            replace(minNum.begin(), minNum.end(), x, '1');
        } else {
            for (int i = 1; i < minNum.length(); ++i) {
                if (minNum[i] == '1' || minNum[i] == '0') continue;
                char x = minNum[i];
                replace(minNum.begin(), minNum.end(), x, '0');
                break;
            }
        }
        return stoi(maxNum) - stoi(minNum);
    }
};

int main() {
    Solution solution; 
    cout << solution.maxDiff(123) << endl; // 99009
}