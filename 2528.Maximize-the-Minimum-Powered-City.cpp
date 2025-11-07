#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        const int n = stations.size();
        vector<long long> diff(n + 1);
        for (int i = 0; i < n; ++i) {
            int left = max(i - r, 0);
            int right = min(i + r + 1, n);
            diff[left] += stations[i];
            diff[right] -= stations[i];
        }
        
        long long low = *min_element(stations.begin(), stations.end());
        long long high = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long result = low;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid, k, diff, n, r)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
private:
    bool canAchieve(const long long targetPower, int k, vector<long long> diff, const int n, const int r) {
        long long curPower = 0;
        for (int i = 0; i < n; ++i) {
            curPower += diff[i];
            if (curPower < targetPower) {
                long long stationsToAdd = targetPower - curPower;
                if (stationsToAdd > k) return false;
                k -= stationsToAdd;
                curPower += stationsToAdd;

                int right = min(i + 2 * r + 1, n);
                diff[right] -= stationsToAdd;
            }
        }
        return true;
    }
};

int main() {
    Solution solution; 
    vector<int> stations = {1,2,4,5,0};
    cout << solution.maxPower(stations,1,2) << endl; // 5
}