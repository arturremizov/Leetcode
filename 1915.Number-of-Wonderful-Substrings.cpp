#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> count;
        count[0] = 1;
        long long result = 0;
        int bitmask = 0;
        for (char c : word) {
            int charIndex = c - 'a';
            bitmask ^= 1 << charIndex;
            result += count[bitmask];
            for (int i = 0; i < 10; i++) {
                result += count[bitmask ^ (1 << i)];
            }
            count[bitmask]++;
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    cout << solution.wonderfulSubstrings("aba") << endl; // 4
    cout << solution.wonderfulSubstrings("aabb") << endl; // 9
}