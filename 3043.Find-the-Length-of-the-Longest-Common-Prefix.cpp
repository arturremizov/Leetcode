#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() > arr2.size()) {
            swap(arr1, arr2);
        }

        unordered_set<int> prefixSet;
        for (int num : arr1) {
            while (num > 0 && !prefixSet.count(num)) {
                prefixSet.insert(num);
                num /= 10;
            }
        } 

        int result = 0;
        for (int num : arr2) {
            while (num > 0 && !prefixSet.count(num)) {
                num /= 10;
            }

            if (num > 0) {
                result = max(result, (int)to_string(num).length());
            }
        }
        return result;       
    }
};

int main() {
    Solution solution; 
    vector<int> arr1 = {1,10,100};
    vector<int> arr2 = {1000};
    cout << solution.longestCommonPrefix(arr1, arr2) << endl; // 3
}