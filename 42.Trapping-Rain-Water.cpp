#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int result = 0;
        while (left < right) {
            if (leftMax < rightMax) {
                leftMax = max(leftMax, height[++left]);
                result += leftMax - height[left];
            } else {
                rightMax = max(rightMax, height[--right]);
                result += rightMax - height[right];
            }
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << solution.trap(height1) << endl;
    vector<int> height2 = {4,2,0,3,2,5};
    cout << solution.trap(height2) << endl;
}