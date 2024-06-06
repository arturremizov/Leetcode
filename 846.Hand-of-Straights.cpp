#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int n = hand.size();
        if (n % groupSize) return false;

        unordered_map<int, int> count;
        for (int num : hand) {
            count[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& [key, _] : count) {
            minHeap.push(key);
        }
        while (!minHeap.empty()) {
            int firstNum = minHeap.top();
            for (int i = firstNum; i < firstNum + groupSize; ++i) {
                if (count[i] == 0) return false;
                count[i]--;
                if (count[i] == 0) {
                    if (i != minHeap.top()) return false;
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};

int main() 
{
    Solution solution; 
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    cout << solution.isNStraightHand(hand, 3) << endl; // true
    vector<int> hand2 = {1,2,3,4,5};
    cout << solution.isNStraightHand(hand2, 4) << endl; // false
}