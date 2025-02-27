#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int n = arr.size();
        unordered_set<int> arrSet(arr.begin(), arr.end());
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int prev = arr[i], curr = arr[j];
                int next = prev + curr;
                int length = 2;
                while (arrSet.count(next)) {
                    prev = curr;
                    int tempNext = next;
                    next = curr + next;
                    curr = tempNext;
                    ++length;
                }
                if (length > 2) {
                    result = max(result, length);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << solution.lenLongestFibSubseq(arr) << endl; // 5
}