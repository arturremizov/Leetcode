#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n = fruits.size();
        int result = 0;
        for (int fruit : fruits) {
            int unplaced = 1;
            for (int i = 0; i < n; ++i) {
                if (fruit > baskets[i]) continue;
                unplaced = 0;
                baskets[i] = 0;
                break;
            }
            result += unplaced;
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};
    cout << solution.numOfUnplacedFruits(fruits, baskets) << endl; // 1
}