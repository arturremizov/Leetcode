#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left == right) return;

        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
        return;
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> leftPart(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> rightPart(nums.begin() + mid + 1, nums.begin() + right + 1);

        int i = left, j = 0, k = 0;
        while (j < leftPart.size() && k < rightPart.size()) {
            if (leftPart[j] <= rightPart[k]) {
                nums[i] = leftPart[j];
                ++j;
            } else {
                nums[i] = rightPart[k];
                ++k;
            }
            ++i;
        }
        while (j < leftPart.size()) {
            nums[i] = leftPart[j];
            ++j, ++i;
        }
        while (k < rightPart.size()) {
            nums[i] = rightPart[k];
            ++k, ++i;
        }
    }
};

int main() 
{
    Solution solution; 
    vector<int> nums = {5,2,3,1};
    vector<int> result = solution.sortArray(nums); // [1,2,3,5]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}