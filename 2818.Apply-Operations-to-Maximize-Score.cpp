#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        const int n = nums.size();
        int result = 1;
        vector<int> primeScores = getPrimeScores(nums);

        vector<int> leftBound(n, -1);
        vector<int> rightBound(n, n);
        stack<int> stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && primeScores[stack.top()] < primeScores[i]) {
                int index = stack.top();
                stack.pop();
                rightBound[index] = i;
            }
            if (!stack.empty()) {
                leftBound[i] = stack.top();
            }            
            stack.push(i);
        } 

        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; ++i) {
            maxHeap.push({nums[i], i});
        }

        while (k > 0) {
            auto [num, index] = maxHeap.top();
            maxHeap.pop();
            int score = primeScores[index];
            int leftCount = index - leftBound[index];
            int rightCount = rightBound[index] - index;
            
            long long count = (long long)leftCount * rightCount;
            int operations = min(count, (long long)k);
            result = (1LL * result * modExponentiation(num, operations, MOD)) % MOD; 
            k -= operations;
        }
        return result;
    }
private:
    vector<int> getPrimeScores(vector<int>& nums) {
        vector<int> primeScores;
        for (int num : nums) {
            int score = 0;
            for (int i = 2; i < sqrt(num)+1; ++i) {
                if (num % i == 0) {
                    ++score;
                    while (num % i == 0) {
                        num /= i;
                    }
                }
            }
            if (num >= 2) ++score;
            primeScores.push_back(score);
        }
        return primeScores;
    }
    int modExponentiation(int base, int exp, int mod) {
        long long result = 1, x = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            exp /= 2;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> nums = {8,3,9,3,8};  
    cout << solution.maximumScore(nums, 2) << endl; // 81
}