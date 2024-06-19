#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const unsigned int n = bloomDay.size();
        if ((unsigned int)m * k > n) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = (left + right) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                ++flowers;
                if (flowers == k) {
                    ++bouquets;
                    flowers = 0;
                    if (bouquets == m) {
                        return true;
                    }
                }
            } else {
                flowers = 0;
            }
        }
        return false;
    }
};

int main() 
{
    Solution solution; 
    vector<int> bloomDay1 = {1,10,3,10,2};
    cout << solution.minDays(bloomDay1, 3, 1) << endl; // 3
    vector<int> bloomDay2 = {1,10,3,10,2};
    cout << solution.minDays(bloomDay2, 3, 2) << endl; // -1
}