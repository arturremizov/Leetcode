#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if (visited.count("0000")) return -1;
        
        while (!queue.empty()) {
            string value = queue.front().first;
            int turns = queue.front().second;
            if (value == target) return turns;
            queue.pop();
            for (string combination : getCombinations(value)) {
                if (!visited.count(combination)) {
                    visited.insert(combination);
                    queue.push({combination, turns + 1});
                }
            }
        }
        return -1;
    }
private:
    vector<string> getCombinations(string value) {
        vector<string> result;
        for (int i = 0; i < 4; ++i) {
            for (int turn : {1, -1}) {
                int newDigit = ((value[i] - '0') + turn + 10) % 10;
                string newValue = value;
                newValue[i] = '0' + newDigit;
                result.push_back(newValue);
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    cout << solution.openLock(deadends, "0202") << endl; // 6

    vector<string> deadends2 = {"8888"};
    cout << solution.openLock(deadends2, "0009") << endl; // 1

    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    cout << solution.openLock(deadends3, "8888") << endl; // -1
}