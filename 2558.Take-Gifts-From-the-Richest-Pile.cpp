#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            int value = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(value));
        }
        long long result = 0;
        while (!maxHeap.empty()) {
            result += maxHeap.top();
            maxHeap.pop();
        }
        return result; 
    }
};

int main() {
    Solution solution; 
    vector<int> gifts = {25,64,9,4,100};
    cout << solution.pickGifts(gifts, 4) << endl; // 29
}