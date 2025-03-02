#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < n && j < m) {
            int id1 = nums1[i][0], id2 = nums2[j][0];
            if (id1 == id2) {
                result.push_back({id1, nums1[i][1] + nums2[j][1]});
                ++i, ++j;
            } else if (id1 < id2) {
                result.push_back(nums1[i]);
                ++i;
            } else {
                result.push_back(nums2[j]);
                ++j;
            }
        }
        while (i < n) {
            result.push_back(nums1[i++]);
        }
        while (j < m) {
            result.push_back(nums2[j++]);
        }
        return result;
    }
};

int main() {
    Solution solution; 
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};
    vector<vector<int>> result = solution.mergeArrays(nums1, nums2); //[[1,6],[2,3],[3,2],[4,6]]
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}