#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int n = s1.length(), m = s2.length();
        if (n > m) return false;

        vector<int> s1Count(26), s2Count(26);
        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                ++matches;
            }
        }

        int left = 0;
        for (int right = n; right < m; right++) {
            if (matches == 26) return true;

            int index = s2[right] - 'a';
            s2Count[index]++;
            if (s1Count[index] == s2Count[index]) {
                matches += 1;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches -= 1;
            }


            index = s2[left] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matches += 1;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matches -= 1;
            }
            ++left;
        }
        return matches == 26 ? true : false;
    }
};

int main() {
    Solution solution; 
    cout << solution.checkInclusion("ab", "eidbaooo") << endl; // true
}