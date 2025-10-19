#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        const int n = s.length();
        queue<string> queue;
        queue.push(s);
        unordered_set<string> visited { s };
        string result = s;
        while (!queue.empty()) {
            string curStr = queue.front();
            queue.pop();
            result = min(result, curStr);
            
            // add a
            for (int i = 1; i < n; i += 2) {
                int num = curStr[i] - '0';
                int updatedNum = (num + a) % 10;
                curStr[i] = updatedNum + '0';
            }
            if (!visited.count(curStr)) {
                visited.insert(curStr);
                queue.push(curStr);
            }

            // rotate by b 
            string rotatedStr = curStr.substr(n - b) + curStr.substr(0, n - b);
            if (!visited.count(rotatedStr)) {
                visited.insert(rotatedStr);
                queue.push(rotatedStr);
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    cout << solution.findLexSmallestString("5525",9,2) << endl; // 2050
}