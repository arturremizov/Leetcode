#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9+7;
        const int n = corridor.length();
        vector<int> indexOfSeats;
        for (int i = 0; i < n; ++i) {
            if (corridor[i] == 'S') {
                indexOfSeats.push_back(i);
            }
        }
        const int seatsTotal = indexOfSeats.size();
        if (seatsTotal < 2 || seatsTotal % 2 == 1) return 0;
        int result = 1;
        for (int i = 1; i < seatsTotal - 1; i += 2) {
            result = (1LL * result * (indexOfSeats[i + 1] - indexOfSeats[i])) % MOD;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.numberOfWays("SSPPSPS") << endl; // 3
}