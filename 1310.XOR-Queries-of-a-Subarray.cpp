#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> previx = {0};
        for (int num : arr) {
            previx.push_back(previx.back() ^ num);
        }

        vector<int> result;
        for (auto query : queries) {
            int left = query[0], right = query[1];
            result.push_back(previx[right + 1] ^ previx[left]);
        }
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1}, {1,2}, {0,3}, {3,3}};
    vector<int> result = solution.xorQueries(arr, queries); // [2,7,14,8]
    for (int i = 0; i < result.size(); ++i) { 
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        } else {
            cout << endl;
        }
    }
}