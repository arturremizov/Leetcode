#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long result = 0;
        for (int i = 0; i < k; ++i) {
            result += max(0, happiness[i] - i);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> happiness = {1,2,3};
    cout << solution.maximumHappinessSum(happiness, 2) << endl; // 4
    vector<int> happiness2 = {1,1,1,1};
    cout << solution.maximumHappinessSum(happiness2, 2) << endl; //  1
    vector<int> happiness3 = {2,3,4,5};
    cout << solution.maximumHappinessSum(happiness3, 1) << endl; // 5
}