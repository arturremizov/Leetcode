#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int n = skill.size();
        long long total = reduce(skill.begin(), skill.end(), 0LL);
        if (total % (n / 2) != 0) return -1;

        unordered_map<int, int> countMap;
        for (int value : skill) countMap[value]++;
        int target = total / (n / 2);
        long long result = 0;   
        for (int value : skill) {
            if (countMap[value] == 0) continue;

            int diff = target - value;
            if (countMap[diff] == 0) return -1;

            result += value * diff;
            countMap[value]--;
            countMap[diff]--;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> skill = {3,2,5,1,3,4};
    cout << solution.dividePlayers(skill) << endl; // 22
}