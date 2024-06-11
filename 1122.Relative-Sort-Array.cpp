#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm> 

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr2Set(arr2.begin(), arr2.end());
        vector<int> secondPartResult;
        unordered_map<int, int> count;
        for (int num : arr1) {
            if (!arr2Set.count(num)) {
                secondPartResult.push_back(num);
            } else {
                count[num]++;
            }
        }
        sort(secondPartResult.begin(), secondPartResult.end());


        vector<int> result;
        for (int num : arr2) {
            for (int i = 0; i < count[num]; ++i) {
                result.push_back(num);
            }            
        }
        result.insert(result.end(), secondPartResult.begin(), secondPartResult.end());
        return result;
    }
};

int main() 
{
    Solution solution; 
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> result = solution.relativeSortArray(arr1, arr2); // [2,2,2,1,4,3,3,9,6,7,19]
    for (int num : result) { 
        cout << num << endl;
    }
}