#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        int i = 1;
        while (i < k) {
            int steps = count(current, n);
            if (i + steps <= k) {
                current = current + 1;
                i += steps;
            } else {
                current *= 10;
                ++i;
            }
        }
        return current;
    }
private:
    int count(long long current, int n) {
        int result = 0;
        long long neighbor = current + 1;
        while (current <= n) {
            neighbor = min(neighbor, (long long)n + 1);
            result += neighbor - current;
            current *= 10;
            neighbor *= 10;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.findKthNumber(13, 2) << endl; // 10
}