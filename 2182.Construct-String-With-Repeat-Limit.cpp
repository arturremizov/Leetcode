#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> countMap;
        for (char c : s) countMap[c]++;
        
        priority_queue<pair<char, int>> maxHeap;
        for (auto [c, count] : countMap) {
            maxHeap.push({c, count});
        }

        string result;
        while (!maxHeap.empty()) {
            auto [c, count] = maxHeap.top();
            maxHeap.pop();

            result.append(min(count, repeatLimit), c);

            if (count - repeatLimit > 0 && !maxHeap.empty()) {
                auto [nextChar, nextCount] = maxHeap.top();
                maxHeap.pop();
                result += nextChar;
                if (nextCount - 1 > 0) {
                    maxHeap.push({nextChar, nextCount - 1});
                }

                maxHeap.push({c, count - repeatLimit});
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.repeatLimitedString("cczazcc", 3) << endl; 
}