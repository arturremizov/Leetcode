#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result = 0;
        unordered_map<int, int> elements;
        for (string word : words) {
            int char1 = word[0] - 'a';
            int char2 = word[1] - 'a';
            elements[char1 * 100 + char2]++;
        }
        bool countEqual = false;
        for (auto [el, count] : elements) {
            int char1 = el / 100;
            int char2 = el % 100;
            int nextElement = char2 * 100 + char1;
            if (char1 == char2) {
                if (count % 2 == 1) {
                    if (!countEqual) {
                        result += 2;
                        countEqual = true;
                    }
                    --count;
                }
                result += count * 2;
            } else if (elements.count(nextElement) && char1 != char2) {
                result += min(count, elements[nextElement]) * 2;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"ab","ty","yt","lc","cl","ab"};
    cout << solution.longestPalindrome(nums) << endl; // 8
}