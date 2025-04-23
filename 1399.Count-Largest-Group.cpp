#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        int maxGroupSize = 0;
        unordered_map<int, int> groups;
        for (int num = 1; num <= n; ++num) {
            int sum = sumOfDigits(num);
            groups[sum]++;
            maxGroupSize = max(maxGroupSize, groups[sum]);
        }
        int result = 0;
        for (auto [_, size] : groups) {
            if (maxGroupSize == size) {
                ++result;
            }
        }
        return result;
    }
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution; 
    cout << solution.countLargestGroup(13) << endl; // 4
}
