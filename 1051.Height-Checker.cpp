#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        const int n = heights.size();
        const int k = 100;

        vector<int> count(k + 1);
        for (int height : heights) {
            count[height]++;
        }

        vector<int> expected;
        for (int height = 1; height <= k; ++height) {
            int curr_count = count[height];
            for (int i = 0; i < curr_count; ++i) {
                expected.push_back(height);
            }
        }
               
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] != expected[i]) {
                ++result;
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> heights = {1,1,4,2,1,3};
    cout << solution.heightChecker(heights) << endl; // 3
    vector<int> heights2 = {5,1,2,3,4};
    cout << solution.heightChecker(heights2) << endl; // 5
}