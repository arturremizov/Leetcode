#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        int minRank = *min_element(ranks.begin(), ranks.end());
        long long right = (long long)minRank * cars * cars;
        long long result = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long repairedCars = countRepairedCars(mid, ranks);
            if (repairedCars >= cars) {
                right = mid - 1;
                result = mid;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
private:
    long long countRepairedCars(long long time, vector<int>& ranks) {
        long long count = 0;
        for (int rank : ranks) {
            count += sqrt(time / rank);
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> ranks = {4,2,3,1};
    cout << solution.repairCars(ranks, 10) << endl; // 16
}