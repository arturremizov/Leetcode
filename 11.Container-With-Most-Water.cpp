#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            result = max(result, minHeight * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(height) << endl; // 49
}