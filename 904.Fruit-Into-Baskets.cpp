#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int n = fruits.size();
        int result = 0;
        int total = 0;
        unordered_map<int,int> treesCount;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            treesCount[fruits[right]]++;
            total++;
            while (treesCount.size() > 2) {
                int fruit = fruits[left++];
                treesCount[fruit]--;
                total--;
                if (treesCount[fruit] == 0) {
                    treesCount.erase(fruit);
                }
            }
            result = max(result, total);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    cout << solution.totalFruit(fruits) << endl; // 5
}