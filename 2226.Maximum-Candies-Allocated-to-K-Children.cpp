#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if (total < k) return 0;
        
        long long left = 1, right = total / k;
        long long result = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long currentCount = 0;
            for (int candy : candies) {
                if (candy >= mid) {
                    currentCount += candy / mid;
                }
                if (currentCount >= k) break; 
            }
            if (currentCount >= k) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candies = {5,8,6};
    cout << solution.maximumCandies(candies,3) << endl; // 5
}