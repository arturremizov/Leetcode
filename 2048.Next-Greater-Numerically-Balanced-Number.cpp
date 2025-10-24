#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        string numStr = to_string(n);
        vector<long long> count(10, 0);
        long long result = generate(n, 0, numStr.length(), count);
        if (result != -1) return result;
        count.assign(10, 0);
        return generate(0, 0, numStr.length() + 1, count);
    }
private:
    long long generate(int num, long long curNum, int length, vector<long long>& count) {
        if (length == 0) {
            if (curNum > num) {
                for (int digit = 1; digit <= 9; ++digit) {
                    if (count[digit] > 0 && count[digit] != digit) return -1;
                }
                return curNum;
            } else {
                return -1;
            }
        }

        long long result = -1;
        for (int digit = 1; digit <= 9; ++digit) {
            if (count[digit] < digit && digit - count[digit] <= length) {
                count[digit]++;
                result = generate(num, curNum * 10 + digit, length - 1, count);
                count[digit]--;
                if (result != -1) break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.nextBeautifulNumber(3000) << endl; // 3133
}