#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        priority_queue<pair<int, char>> maxHeap;
        vector<pair<int, char>> charCount = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        for (auto [count, c] : charCount) {
            if (count == 0) continue;
            maxHeap.push({count, c});
        }

        while (!maxHeap.empty()) {
            auto [count, c] = maxHeap.top();
            maxHeap.pop();
            int length = result.length();
            if (length > 1 && result[length - 1] == c && result[length - 2] == c) {
                if (maxHeap.empty()) break;
                auto [count2, c2] = maxHeap.top();
                maxHeap.pop();
                result += c2;
                if (--count2 > 0) {
                    maxHeap.push({count2, c2});
                }
            } else {
                result += c;
                --count;
            }
            
            if (count > 0) {
                maxHeap.push({count, c});    
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.longestDiverseString(1,1,7) << endl; // "ccbccacc"
}