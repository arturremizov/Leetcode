#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const int n = words.size();
        int result = n;
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int distance = abs(i - startIndex);
                result = min({result, distance, n - distance});
            }
        }
        return result == n ? -1 : result;
    }
};

int main() {
    Solution solution; 
    vector<string> words = {"a","b","leetcode"};
    cout << solution.closestTarget(words, "leetcode", 0) << endl; // 1
}